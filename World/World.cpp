//
// Created by florent on 30/08/2025.
//

#include "World.h"

#include <iostream>
#include <ostream>
#include <random>
#include "../creature/fish/Fish.h"
#include "../interface/Interface.h"
#include "../creature/velocity/Velocity.h"

std::vector<Fish> World::getFishs() {
    return fishes;
}

void World::createFishs() {
    for (int i=0; i< fishCount; i++) {
        Position position = fishesPositions[i];
        Velocity velocity(0.0, 0.0);
        Fish fish(i, position, velocity);
        fishes.push_back(fish);
    }
}

void World::generatePositionOfFishs() {
    fishesPositions.clear();
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> positionX(0, WIDTH);
    std::uniform_int_distribution<int> positionY(0, HEIGHT);

    for (int i=0; i< fishCount; i++) {
        Position position(positionX(gen), positionY(gen));
        fishesPositions.push_back(position);
    }
}

void World::adaptPosition(Position &position, Velocity &velocity) {
    if (position.getX() < 0) {
        position.setX(0);
        velocity.setVx(-velocity.getVx() * RESTITATION_COEFFICIENT);
    }
    else if (position.getX() > WIDTH) {
        position.setX(WIDTH);
        velocity.setVx(-velocity.getVx() * RESTITATION_COEFFICIENT);
    }
    if (position.getY() < 0) {
        position.setY(0);
        velocity.setVy(-velocity.getVy() * RESTITATION_COEFFICIENT);
    }
    else if (position.getY() > HEIGHT) {
        position.setY(HEIGHT);
        velocity.setVy(-velocity.getVy() * RESTITATION_COEFFICIENT);
    }
}

bool World::adaptVelocity(Fish &fish) {
    if (fish.getVelocity().length() > MAX_VELOCITY) {
        return true;
    }
    return false;
}

std::vector<Fish> World::fishPerception(Fish &fish) {
    double x = fish.getPosition().getX();
    double y = fish.getPosition().getY();
    std::vector<Fish> nearFishes;

    for (Fish &f : fishes) {
        double xFish = f.getPosition().getX();
        double yFish = f.getPosition().getY();
        double enclideanDistance = sqrt(pow(xFish - x, 2) + pow(yFish - y, 2));
        if (enclideanDistance < PERCEPTION_RADIUS && fish != f) {
            nearFishes.push_back(f);
        }
    }
    return nearFishes;
}

void World::mean(std::vector<Fish> fishes, double &meanX, double &meanY) {
    double sumX = 0.0;
    double sumY = 0.0;
    for (Fish &f : fishes) {
        sumX += f.getPosition().getX();
        sumY += f.getPosition().getY();
    }
    meanX = sumX / fishes.size();
    meanY = sumY / fishes.size();
}

/**
 * @brief Setup of the 1st rule: Cohesion
 * @param fish
 */
Vector2d World::cohesion(Fish &fish) {
    std::vector<Fish> nearFishes = fishPerception(fish);
    if (nearFishes.empty()) {
        return Vector2d(0.0, 0.0);
    }
    double meanX = 0.0, meanY = 0.0;
    mean(fishes, meanX, meanY);

    Vector2d vectorCohesion = Vector2d(meanX - fish.getPosition().getX(), meanY - fish.getPosition().getY());
    vectorCohesion = vectorCohesion.normalize() * COHESION_COEFFICIENT;
    return vectorCohesion;
}

Vector2d World::separationForce(Fish &fish) {
    double x = fish.getPosition().getX();
    double y = fish.getPosition().getY();
    Vector2d separationVector(0.0, 0.0);

    for (Fish &f : fishes) {
        double xFish = f.getPosition().getX();
        double yFish = f.getPosition().getY();
        Vector2d temp(0.0, 0.0);
        double enclideanDistance = sqrt(pow(xFish - x, 2) + pow(yFish - y, 2));
        if (enclideanDistance < SEPARATION_RADIUS && fish != f) {
            temp = Vector2d(x - f.getPosition().getX(), y - f.getPosition().getY());
            if (temp.lengh() > 0.0) {
                temp = temp.normalize();
            }

            separationVector = temp + separationVector;
        }
    }
    return separationVector * SEPARATION_COEFFICIENT;
}

/**
 * @brief Setup of the 2nd rule: Separation
 * @param fish
 */
Vector2d World::separation(Fish &fish) {
    Vector2d vecteurSeparation = separationForce(fish);
    vecteurSeparation = vecteurSeparation * SEPARATION_COEFFICIENT;
    return vecteurSeparation;
}

void World::meanVelocity(std::vector<Fish> fishes, double &meanX, double &meanY) {
    for (Fish &f : fishes) {
        meanX += f.getVelocity().getVx();
        meanY += f.getVelocity().getVy();
    }
    meanX /= fishes.size();
    meanY /= fishes.size();
}

/**
 * @brief Setup of the 3rd and final rule: alignment
 * @param fish
 */
Vector2d World::alignment(Fish &fish) {
    std::vector<Fish> nearFishes = fishPerception(fish);
    if (nearFishes.empty()) {
        return Vector2d(0.0, 0.0);
    }

    double meanVx = 0.0;
    double meanVy = 0.0;
    mean(nearFishes, meanVx, meanVy);
    Vector2d vectorAlignment = Vector2d(meanVx, meanVy) - Vector2d(fish.getVelocity().getVx(), fish.getVelocity().getVy());
    vectorAlignment = vectorAlignment.normalize() * ALIGNMENT_COEFFICIENT;
    return vectorAlignment;
}

void World::worldUpdate(double deltaTime) {
    for (Fish &f : fishes) {
        Vector2d forceCohesion = cohesion(f);
        Vector2d forceSeparation = separationForce(f);
        Vector2d forceAlignment = alignment(f);

        Velocity newVelocity = f.getVelocity() + forceCohesion + forceSeparation + forceAlignment;

        if (newVelocity.getVx() > 1 || !newVelocity.getVy() > 1) {
            std::cout << newVelocity.getVx() << std::endl;
            std::cout << newVelocity.getVy() << std::endl;
            std::cout << std::endl;
        }

        if (newVelocity.length() > MAX_VELOCITY) {
            newVelocity = newVelocity.normalize() * MAX_VELOCITY;
        }

        Position newPosition(
            f.getPosition().getX() + newVelocity.getVx() * deltaTime,
            f.getPosition().getY() + newVelocity.getVy() * deltaTime
        );

        adaptPosition(newPosition, newVelocity);

        f.setVelocity(newVelocity);
        f.setPosition(newPosition);
    }
}

void World::initWorld() {
    generatePositionOfFishs();
    createFishs();
}

//
// Created by florent on 30/08/2025.
//

#include "World.h"
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
        Velocity velocity(0.0, 0);
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

bool World::controlPositionX(Fish &fish) {
    Position position = fish.getPosition();
    if (position.getX() >= WIDTH || position.getX() < 0) {
        return true;
    }
    return false;
}

bool World::controlPositionY(Fish &fish) {
    Position position = fish.getPosition();
    if (position.getY() >= HEIGHT || position.getY() < 0) {
        return true;
    }
    return false;
}


void World::adaptPosition(Fish &fish) {
    if (controlPositionX(fish)) {
        if (fish.getPosition().getX() >= WIDTH) {
            Position newPosition(fish.getPosition().getX() - WIDTH, fish.getPosition().getY());
            fish.setPosition(newPosition);
        }else {
            Position newPosition(fish.getPosition().getX() + WIDTH, fish.getPosition().getY());
            fish.setPosition(newPosition);
        }
    }
    else if (controlPositionY(fish)) {
        if (fish.getPosition().getY() >= HEIGHT) {
            Position newPosition(fish.getPosition().getX(), fish.getPosition().getY() - HEIGHT);
            fish.setPosition(newPosition);
        }else {
            Position newPosition(fish.getPosition().getX(), fish.getPosition().getY() + HEIGHT);
            fish.setPosition(newPosition);
        }

    }
}

void World::worldUpdate(double deltaTime) {
    for (Fish &f : fishes) {
        double x = f.getPosition().getX();
        double y = f.getPosition().getY();

        double newX = x + deltaTime * f.getVelocity().getVx();
        double newY = y + deltaTime * f.getVelocity().getVy();
        Position newPosition(newX, newY);
        f.setPosition(newPosition);
        adaptPosition(f);
    }
}

void World::initWorld() {
    generatePositionOfFishs();
    createFishs();
}

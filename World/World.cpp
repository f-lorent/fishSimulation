//
// Created by florent on 30/08/2025.
//

#include "World.h"
#include <random>
#include "../creature/fish/Fish.h"
#include "../interface/Interface.h"
#include "../creature/velocity/Velocity.h"


void World::createFishs() {
    for (int i=0; i< fishCount; i++) {
        Position position = fishesPositions[i];
        Velocity velocity(10.0, 0);
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

void World::worldUpdate(double deltaTime) {
    for (Fish &f : fishes) {
        double x = f.getPosition().getX();
        double y = f.getPosition().getY();

        double newX = x + deltaTime * f.getVelocity().getVx();
        double newY = y + deltaTime * f.getVelocity().getVy();
        Position newPosition(newX, newY);
        f.setPosition(newPosition);
    }
}

std::vector<Fish> World::getFishs() {
    return fishes;
}

void World::initWorld() {
    generatePositionOfFishs();
    createFishs();
}

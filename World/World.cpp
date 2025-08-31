//
// Created by florent on 30/08/2025.
//

#include "World.h"

#include <random>

#include "../creature/fish/Fish.h"
#include "../interface/Interface.h"


void World::createFishs() {
    for (int i=0; i< fishCount; i++) {
        Position position = fishesPositions[i];
        Fish fish(i, position);
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

std::vector<Fish> World::getFishs() {
    return fishes;
}


void World::initWorld() {
    generatePositionOfFishs();
    createFishs();
}

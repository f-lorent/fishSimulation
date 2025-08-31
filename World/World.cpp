//
// Created by florent on 30/08/2025.
//

#include "World.h"
#include "../creature/fish/Fish.h"


void World::createFishs() {
    for (int i=0; i< fishCount; i++) {
        Position position(110.0, 110.0);
        Fish fish(i, position);
        fishes.push_back(fish);
    }
}

std::vector<Fish> World::getFishs() {
    return fishes;
}


void World::initWorld() {
    createFishs();
}

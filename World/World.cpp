//
// Created by florent on 30/08/2025.
//

#include "World.h"


void World::createFishs() {
    for (int i=0; i< fishCount; i++) {
        Position position(0.0, 0.0);
        Fish fish(i, position);
        fishes.push_back(fish);
    }
}


void World::initWorld() {
    createFishs();
}
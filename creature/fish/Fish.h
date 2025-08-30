//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_FISH_H
#define FISHSIMULATION_FISH_H

#include "../position/Position.h"

class Fish {
private:
    int id;
    Position position;

public:
    Fish(int id, Position position) : id(id), position(position) {}
    Position getPosition();
    int getId();
};


#endif //FISHSIMULATION_FISH_H
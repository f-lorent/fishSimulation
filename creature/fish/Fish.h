//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_FISH_H
#define FISHSIMULATION_FISH_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../position/Position.h"

#define FISH_RADIUS 2

class Fish {
private:
    int id;
    Position position;

public:
    Fish(int id, Position position) : id(id), position(position) {}
    Position getPosition();
    void setPosition(Position position);
    int getId();
    void drawFish(sf::RenderWindow* window);
};


#endif //FISHSIMULATION_FISH_H
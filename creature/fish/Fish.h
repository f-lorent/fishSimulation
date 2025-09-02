//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_FISH_H
#define FISHSIMULATION_FISH_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../position/Position.h"
#include "../velocity/Velocity.h"

#define FISH_RADIUS 1
#define PERCEPTION_RADIUS 80 // between 80 - 120 px
#define SEPARATION_RADIUS 20 // between 20 - 30 px
#define MAX_VELOCITY 10.0 // between 120 - 180

class Fish {
private:
    int id;
    Position position;
    Velocity velocity;

public:
    Fish(int id, Position position, Velocity velocity) : id(id), position(position), velocity(velocity) {}
    Position getPosition();
    void setPosition(Position position);
    Velocity getVelocity();
    void setVelocity(Velocity velocity);
    int getId();
    void drawFish(sf::RenderWindow* window);

    bool operator==(const Fish& other) const;
};


#endif //FISHSIMULATION_FISH_H
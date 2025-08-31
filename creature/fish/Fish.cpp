//
// Created by florent on 30/08/2025.
//

#include "Fish.h"
#include <SFML/Graphics.hpp>

int Fish::getId() {
    return id;
}

void Fish::setPosition(Position position) {
    this->position = position;
}

Position Fish::getPosition() {
    return position;
}

Velocity Fish::getVelocity() {
    return velocity;
}

void Fish::setVelocity(Velocity velocity) {
    this->velocity = velocity;
}

void Fish::drawFish(sf::RenderWindow* window) {
    sf::CircleShape fishShape(FISH_RADIUS);
    fishShape.setPosition(getPosition().getX(), getPosition().getY());
    window->draw(fishShape);
}

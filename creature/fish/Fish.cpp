//
// Created by florent on 30/08/2025.
//

#include "Fish.h"
#include <SFML/Graphics.hpp>

int Fish::getId() {
    return id;
}

Position Fish::getPosition() {
    return position;
}

void Fish::drawFish(sf::RenderWindow* window) {
    sf::CircleShape fishShape(FISH_RADIUS);
    fishShape.setPosition(getPosition().getX(), getPosition().getY());
    window->draw(fishShape);
}

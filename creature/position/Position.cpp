//
// Created by florent on 30/08/2025.
//

#include "Position.h"

Position::Position(double x, double y) {
    this->x = x;
    this->y = y;
}

void Position::setX(double newX) {
    this->x = newX;
}

void Position::setY(double newY) {
    this->y = newY;
}

double Position::getX() {
    return x;
}

double Position::getY() {
    return y;
}

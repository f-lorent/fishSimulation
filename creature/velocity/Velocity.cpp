//
// Created by florent on 31/08/2025.
//

#include "Velocity.h"

#include <cmath>
#include <math.h>

double Velocity::getVx() {
    return this->vx;
}

double Velocity::getVy() {
    return this->vy;
}

void Velocity::setVx(double vx) {
    this->vx = vx;
}

void Velocity::setVy(double vy) {
    this->vy = vy;
}

double Velocity::length() {
    return sqrt(this->vx * this->vx + this->vy * this->vy);
}

Velocity Velocity::normalize() {
    return Velocity(vx / length(), vy / length());
}

Velocity Velocity::operator*(const double scalar) const {
    return Velocity(vx * scalar, vy * scalar);
}

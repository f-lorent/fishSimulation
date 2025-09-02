//
// Created by florent on 31/08/2025.
//

#ifndef FISHSIMULATION_VELOCITY_H
#define FISHSIMULATION_VELOCITY_H
#include "../../vector/Vector2d.h"


class Velocity {
private:
    double vx, vy;

    public:
    Velocity(double vX, double vY) {
        this->vx = vX;
        this->vy = vY;
    };
    double getVx();
    double getVy();
    void setVx(double vx);
    void setVy(double vy);

    Velocity operator+(const Vector2d& other) const {
        return Velocity{vx + other.x1(), vy + other.y1()};
    }

    double length();
    Velocity normalize();
    Velocity operator*(const double scalar) const;
};


#endif //FISHSIMULATION_VELOCITY_H
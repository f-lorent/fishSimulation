//
// Created by florent on 31/08/2025.
//

#ifndef FISHSIMULATION_VELOCITY_H
#define FISHSIMULATION_VELOCITY_H


class Velocity {
private:
    double vx, vy;

    public:
    Velocity(int vX, int vY) {
        this->vx = vX;
        this->vy = vY;
    };
    double getVx();
    double getVy();
    void setVx(double vx);
    void setVy(double vy);
};


#endif //FISHSIMULATION_VELOCITY_H
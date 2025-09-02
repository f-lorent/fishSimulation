//
// Created by florent on 30/08/2025.
//

#ifndef FISHSIMULATION_POSITION_H
#define FISHSIMULATION_POSITION_H


class Position {
    private:
    double x;
    double y;

public:
    Position(double x, double y);
    double getX();
    double getY();
    void setX(double newX);
    void setY(double newY);

    Position operator+(const double scalar) const;
};

#endif //FISHSIMULATION_POSITION_H
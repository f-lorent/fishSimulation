//
// Created by florent on 31/08/2025.
//

#ifndef FISHSIMULATION_VECTOR_H
#define FISHSIMULATION_VECTOR_H


class Vector2d {
    double x, y;

    public:
    Vector2d(double x, double y): x(x), y(y) {};
    Vector2d operator+(const Vector2d &other) const;
    Vector2d operator*(const Vector2d &other) const;
    Vector2d operator*(const double scalar) const;
    double lengh() const;
    Vector2d normalize() const;

    [[nodiscard]] double x1() const {
        return x;
    }

    void set_x(double x) {
        this->x = x;
    }

    [[nodiscard]] double y1() const {
        return y;
    }

    void set_y(double y) {
        this->y = y;
    }
};


#endif //FISHSIMULATION_VECTOR_H
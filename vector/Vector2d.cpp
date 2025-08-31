//
// Created by florent on 31/08/2025.
//

#include "Vector2d.h"

#include <cmath>

Vector2d Vector2d::operator+(const Vector2d &other) const {
    return Vector2d(x + other.x, y + other.y);
}

Vector2d Vector2d::operator*(const Vector2d &other) const {
    return Vector2d(x * other.x, y * other.y);
}

double Vector2d::lengh() const {
    return std::sqrt(x * x + y * y);
}

Vector2d Vector2d::normalize() const {
    return Vector2d(x / lengh(), y / lengh());
}

Vector2d Vector2d::operator*(const double scalar) const {
    return Vector2d(x * scalar, y * scalar);
}

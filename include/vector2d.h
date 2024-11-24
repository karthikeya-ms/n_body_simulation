#pragma once
#include <cmath> // For sqrt
#include <cstdlib> // For rand if used



struct Vector2D {
    double x;
    double y;

    Vector2D operator+(const Vector2D& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2D operator-(const Vector2D& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2D operator*(double scalar) const {
        return {x * scalar, y * scalar};
    }

    double magnitude() const {
        return sqrt(x * x + y * y);
    }
};

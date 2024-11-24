#pragma once
#include "vector2d.h"

class Particle {
public:
    Vector2D position;
    Vector2D velocity;
    Vector2D force;
    double mass;

    Particle() : position({0, 0}), velocity({0, 0}), force({0, 0}), mass(1.0) {} // Default constructor

    Particle(Vector2D pos, Vector2D vel, double m);

    void reset_force();
    void add_force(const Vector2D& other_force);
    void update_position(double dt);
};

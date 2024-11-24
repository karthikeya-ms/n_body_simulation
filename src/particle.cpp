#include "particle.h"

Particle::Particle(Vector2D pos, Vector2D vel, double m)
    : position(pos), velocity(vel), mass(m), force({0, 0}) {}

void Particle::reset_force() {
    force = {0, 0}; // Reset force vector
}

void Particle::add_force(const Vector2D& other_force) {
    force.x += other_force.x;
    force.y += other_force.y;
}

void Particle::update_position(double dt) {
    // Update velocity
    velocity.x += (force.x / mass) * dt;
    velocity.y += (force.y / mass) * dt;

    // Update position
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;
}

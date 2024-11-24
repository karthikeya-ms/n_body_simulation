#include "n_body_simulation.h"
#include <cmath>
#include <iostream>

NBodySimulation::NBodySimulation(int num_particles) : particles(num_particles) {}

void NBodySimulation::initialize_particles() {
    for (auto& particle : particles) {
        particle = Particle(
            {static_cast<double>(rand() % 1000), static_cast<double>(rand() % 1000)},
            {0, 0},
            1.0
        );
    }
}


void NBodySimulation::compute_forces() {
    for (size_t i = 0; i < particles.size(); ++i) {
        particles[i].reset_force();
        for (size_t j = 0; j < particles.size(); ++j) {
            if (i != j) {
                Vector2D diff = particles[j].position - particles[i].position;
                double distance = std::max(diff.magnitude(), 1.0); // Avoid division by zero
                double force_magnitude = (particles[i].mass * particles[j].mass) / (distance * distance);
                Vector2D force = diff * (force_magnitude / distance);
                particles[i].add_force(force);
            }
        }
    }
}

void NBodySimulation::update_particles(double dt) {
    for (auto& particle : particles) {
        particle.update_position(dt);
    }
}

void NBodySimulation::simulate_step(double dt) {
    compute_forces();
    update_particles(dt);
}

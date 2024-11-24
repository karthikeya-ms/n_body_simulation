#pragma once
#include "particle.h"
#include <vector>

class NBodySimulation {
private:
    std::vector<Particle> particles; // Still private

public:
    NBodySimulation(int num_particles);
    void initialize_particles();
    void compute_forces();
    void update_particles(double dt);
    void simulate_step(double dt);

    // Getter to access particles
    const std::vector<Particle>& get_particles() const {
        return particles;
    }
};


#include "n_body_simulation.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

// Function to render particles as points
void drawParticles(const std::vector<Particle>& particles) {
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f); // Set particle color (white)
    for (const auto& particle : particles) {
        glVertex2f(particle.position.x / 400.0f - 1.0f, // Normalize position
                   particle.position.y / 400.0f - 1.0f);
    }
    glEnd();
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 800, "N-Body Simulation", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Make the window's OpenGL context current
    glPointSize(2.0f); // Set the size of points for particles

    // Initialize N-Body Simulation
    NBodySimulation simulation(100); // 100 particles
    simulation.initialize_particles();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Handle events
        glfwPollEvents();

        // Simulate one step
        simulation.simulate_step(0.01); // Time step = 0.01

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();

        // Draw particles
        drawParticles(simulation.get_particles());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}



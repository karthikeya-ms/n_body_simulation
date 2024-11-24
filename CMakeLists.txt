cmake_minimum_required(VERSION 3.10)
project(NBodySimulation)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Link GLFW and OpenGL
set(GLFW_DIR "C:/glfw-3.4.bin.WIN64")
include_directories(${GLFW_DIR}/include)
link_directories(${GLFW_DIR}/lib-mingw-w64)

find_package(OpenGL REQUIRED)

# Add the executable
add_executable(n_body_simulation src/main.cpp src/n_body_simulation.cpp src/particle.cpp)

# Link libraries
target_link_libraries(n_body_simulation OpenGL::GL glfw3)




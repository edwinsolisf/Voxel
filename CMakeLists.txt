cmake_minimum_required(VERSION 3.20)

project(Voxel
        VERSION 1.0
        LANGUAGES CXX)

option(OPENGL_ENGINE "Use OpenGL" ON)

if (OPENGL_ENGINE)
    find_package(OpenGL REQUIRED)
endif()

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory(include)
add_subdirectory(src)
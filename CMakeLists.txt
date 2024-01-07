cmake_minimum_required(VERSION 3.26)
project(snake_cube_puzzle)

set(CMAKE_CXX_STANDARD 17)

add_executable(snake_cube_puzzle main.cpp
        snake_cube_solver.h
        snake_cube_solver.cpp
        connectivity_graph.cpp
        connectivity_graph.h
        common.h)

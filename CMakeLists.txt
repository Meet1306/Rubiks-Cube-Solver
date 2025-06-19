cmake_minimum_required(VERSION 3.31)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks_Cube_Solver main.cpp
        Models/GenericRubiksCube.cpp
        Models/GenericRubiksCube.h
        Models/Rubiks_3D_Model.cpp)

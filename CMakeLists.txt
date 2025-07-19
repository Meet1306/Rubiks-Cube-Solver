cmake_minimum_required(VERSION 3.31)
project(Rubiks_Cube_Solver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubiks_Cube_Solver main.cpp
        Models/GenericRubiksCube.cpp
        Models/GenericRubiksCube.h
        Models/Rubiks_3D_Model.cpp
        Models/Rubiks_1D_Model.cpp
        Models/Rubiks_BitBoard_Model.cpp
        Solvers/DFS_Solver.h
        Solvers/BFS_Solver.h
        Solvers/IDDFS_Solver.cpp
        Solvers/IDDFS_Solver.h
        Solvers/IDAstar_Solver.h
        Pattern_Database/math.cpp
        Pattern_Database/math.h
        Pattern_Database/PermutationIndexer.h
        Pattern_Database/Nibble_Array.cpp
        Pattern_Database/Nibble_Array.h
        Pattern_Database/Pattern_Database.cpp
        Pattern_Database/Pattern_Database.h
        Pattern_Database/Corner_Pattern_Database.cpp
        Pattern_Database/Corner_Pattern_Database.h
        Pattern_Database/Corner_DB_Maker.cpp
        Pattern_Database/Corner_DB_Maker.h
)

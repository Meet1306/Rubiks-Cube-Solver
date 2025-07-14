//
// Created by konar on 14-07-2025.
//

#ifndef IDASTAR_SOLVER_H
#define IDASTAR_SOLVER_H


#include "../Models/GenericRubiksCube.h"

template<typename T, typename H>
class IDAstar_Solver {
private:
    int next_bound;
    unordered_map<T,bool,H> visited;
    bool dfs(T& current_cube, int bound);


public:
    T cube;
    vector<GenericRubiksCube::MOVE> solved_moves;

    IDAstar_Solver(T _cube) {};

    vector<GenericRubiksCube::MOVE> solve();
};



#endif //IDASTAR_SOLVER_H

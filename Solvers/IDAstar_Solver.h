//
// Created by Meet on 14-07-2025.
//

#ifndef IDASTAR_SOLVER_H
#define IDASTAR_SOLVER_H

#include "../Models/GenericRubiksCube.h"
#include <bits/stdc++.h>
using namespace std;

template<typename T, typename H>
class IDAstar_Solver {
private:
    int next_bound;
    bool dfs(T& current_cube, int bound, int dep,string &last_mv);

public:
    T cube;
    vector<GenericRubiksCube::MOVE> solved_moves;

    IDAstar_Solver(T _cube);
    vector<GenericRubiksCube::MOVE> solve();
};

template<typename T, typename H>
IDAstar_Solver<T, H>::IDAstar_Solver(T _cube) : cube(_cube) {}

template<typename T, typename H>
bool IDAstar_Solver<T, H>::dfs(T& current_cube, int bound, int dep, string &last_mv) {
    int f = dep;
    if (f > bound) {
        next_bound = min(next_bound, dep);
        return false;
    }
    if (current_cube.isSolved()) return true;

    for (int i = 0; i < 18; i++) {
        string i_mv = GenericRubiksCube::getInverseMove(GenericRubiksCube::MOVE(i));
        if (i_mv==last_mv) {continue;}

        current_cube.move(GenericRubiksCube::MOVE(i));
        last_mv = GenericRubiksCube::getMove(GenericRubiksCube::MOVE(i));
        solved_moves.push_back(GenericRubiksCube::MOVE(i));
        if (dfs(current_cube, bound, dep + 1,last_mv)) return true;
        current_cube.invertMove(GenericRubiksCube::MOVE(i));
        solved_moves.pop_back();
    }
    return false;
}

template<typename T, typename H>
vector<GenericRubiksCube::MOVE> IDAstar_Solver<T, H>::solve() {
    int bound = 1;
    while (true) {
        solved_moves.clear();
        next_bound = INT_MAX;
        T current_cube = cube;

        string temp_mv = "";
        if (dfs(current_cube, bound, 1,temp_mv)) {
            return solved_moves;
        }
        if (next_bound == INT_MAX) break;
        bound = next_bound;
    }

    return {};
}

#endif // IDASTAR_SOLVER_H

//
// Created by Meet on 14-07-2025.
//

#ifndef IDASTAR_SOLVER_H
#define IDASTAR_SOLVER_H

#include "../Models/GenericRubiksCube.h"
#include "../Pattern_Database/Corner_Pattern_Database.h"

#include <bits/stdc++.h>
using namespace std;

template<typename T, typename H>
class IDAstar_Solver {
private:
    Corner_Pattern_Database cornerDB;

    int next_bound;
    bool dfs(T& current_cube, int bound, int dep);

public:
    T cube;
    vector<GenericRubiksCube::MOVE> solved_moves;

    IDAstar_Solver(T _cube,string fileName);
    vector<GenericRubiksCube::MOVE> solve();
};

template<typename T, typename H>
IDAstar_Solver<T, H>::IDAstar_Solver(T _cube,string fileName) : cube(_cube) {
    cornerDB.fromFile(fileName);
}

template<typename T, typename H>
bool IDAstar_Solver<T, H>::dfs(T& current_cube, int bound, int dep) {
    int f = dep + cornerDB.getNumMoves(current_cube);
    if (f > bound) {
        next_bound = min(next_bound, f);
        return false;
    }
    if (current_cube.isSolved()) return true;

    for (int i = 0; i < 18; i++) {
        string i_mv = GenericRubiksCube::getInverseMove(GenericRubiksCube::MOVE(i));

        current_cube.move(GenericRubiksCube::MOVE(i));
        solved_moves.push_back(GenericRubiksCube::MOVE(i));
        if (dfs(current_cube, bound, dep + 1)) return true;
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

        if (dfs(current_cube, bound, 1)) {
            return solved_moves;
        }
        if (next_bound == INT_MAX) break;
        bound = next_bound;
    }

    return {};
}

#endif // IDASTAR_SOLVER_H

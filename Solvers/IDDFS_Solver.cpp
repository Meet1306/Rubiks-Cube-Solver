//
// Created by konar on 12-07-2025.
//

#include "IDDFS_Solver.h"

IDDFS_Solver::IDDFS_Solver(GenericRubiksCube *_cube, int _max_d) : cube(_cube) , max_d(_max_d) {};

bool IDDFS_Solver::iddfs(GenericRubiksCube *cube_state, int depth, int curr_max_depth) {
    if (cube_state->isSolved()) return 1;
    if (depth==curr_max_depth) return false;

    for (int i = 0; i < 18; ++i) {
        auto mv = static_cast<GenericRubiksCube::MOVE>(i);
        solved_moves.push_back(mv);
        cube_state->move(mv);
        if (iddfs(cube_state,depth+1,curr_max_depth)) return 1;
        cube_state->invertMove(mv);
        solved_moves.pop_back();
    }

    return false;
}


vector<GenericRubiksCube::MOVE> IDDFS_Solver::solve() {
    for (int i = 1;i<=max_d;i++) {
        solved_moves.clear();
        if (iddfs(cube,0,i)) {
            return solved_moves;
        }
    }
    return {};
}


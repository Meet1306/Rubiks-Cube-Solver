//
// Created by Meet on 12-07-2025.
//

#ifndef IDDFS_SOLVER_H
#define IDDFS_SOLVER_H

#include "../Models/GenericRubiksCube.h"

class IDDFS_Solver {

private:
    GenericRubiksCube* cube;
    int max_d;

    bool iddfs(GenericRubiksCube* cube_state,int depth,int curr_max_depth);

public:
    vector<GenericRubiksCube::MOVE> solved_moves;
    IDDFS_Solver(GenericRubiksCube* _cube,int _max_d);
    vector<GenericRubiksCube::MOVE> solve();
};


#endif //IDDFS_SOLVER_H

//
// Created by Meet on 27-06-2025.
//

#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H

#include <bits/stdc++.h>
using namespace std;

#include "../Models/GenericRubiksCube.h"

// output is the moves
//input will be class

class DFS_Solver
{
private:
    vector<GenericRubiksCube::MOVE> solved_moves;
    GenericRubiksCube* cube;
    int max_depth;
    bool dfsSolver(int dep)
    {
        //visited map doesn't work here
        if (cube->isSolved())
        {
            return true;
        }
        if (dep > max_depth) return false;

        for (int i = 0; i < 18; ++i)
        {
            auto mv = static_cast<GenericRubiksCube::MOVE>(i);


            cube->move(mv);
            solved_moves.push_back(mv);

            if (dfsSolver(dep + 1))
                return true;

            cube->invertMove(mv);
            solved_moves.pop_back();
        }
        return false;

    }


public:

    DFS_Solver(GenericRubiksCube* _cube,int _max_depth) : cube(_cube), max_depth(_max_depth) {}

    vector<GenericRubiksCube::MOVE> solve()
    {
        solved_moves.clear();
        dfsSolver(1);
        return solved_moves;
    }

};

#endif //DFS_SOLVER_H

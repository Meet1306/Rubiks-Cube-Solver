//
// Created by Meet on 27-06-2025.
//

#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H
#include <bits/stdc++.h>
using namespace std;

#include "../Models/GenericRubiksCube.h"


template<typename T,typename H>
class BFS_Solver
{
private:
    T cube;
    unordered_map<T,bool,H> vis;
    unordered_map<T,GenericRubiksCube::MOVE,H> curr_move;  //move to reach the current state

    T bfssolver()
    {
        vis[cube]=true;
        queue<T> q;
        q.push(cube);
        while (!q.empty())
        {
            T curr = q.front();
            q.pop();
            if (curr.isSolved())
            {
                return curr;
            }

            for (int i = 0;i<18;i++)
            {
                T nxt = curr;
                nxt.move(GenericRubiksCube::MOVE(i));
                if (!vis.count(nxt))
                {
                    q.push(nxt);
                    vis[nxt]=true;
                    curr_move[nxt] = GenericRubiksCube::MOVE(i);
                }

            }
        }
        return cube;

    }



public:
    BFS_Solver(T _cube): cube(_cube) {};

    vector<GenericRubiksCube::MOVE> solve()
    {
        vector<GenericRubiksCube::MOVE> moves;
        T solved_cube = bfssolver();
        while (solved_cube != cube)
        {
            GenericRubiksCube::MOVE mv = curr_move[solved_cube];
            moves.push_back(mv);
            solved_cube.invertMove(mv);
        }
        reverse(moves.begin(),moves.end());
        return moves;

    }
};

#endif //BFS_SOLVER_H

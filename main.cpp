#include <bits/stdc++.h>
using namespace std;

// #include "Models/Rubiks_3D_Model.cpp"
// #include "Models/Rubiks_1D_Model.cpp"
#include "Models/Rubiks_BitBoard_Model.cpp"

// #include "Solvers/DFS_Solver.h"
#include "Solvers/BFS_Solver.h"
int main() {
    // Rubiks_3D_Model cube1;
    // cube1.move(GenericRubiksCube::MOVE::R);
    // cube1.print();


    // Rubiks_3D_Model cube2;
    // cube2 = cube1;
    // cube2.print();


    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(10);
    // cube.print();
    // if (cube.isSolved()) cout<<"Solved"<<endl;


    // Rubiks_1D_Model cube;
    // // cube.print();
    // cout<<cube.isSolved()<<endl;
    //
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(10);
    // for (auto i: moves)
    // {
    //     cout<<Rubiks_1D_Model::getMove(i)<<" ";
    // }
    // cout<<endl;
    // cube.print();
    // cout<<cube.isSolved()<<endl;


    // Rubiks_BitBoard_Model cube;
    // cube.f();
    // cube.print();

    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(10);
    // for (auto i: moves)
    // {
    //     cout<<Rubiks_BitBoard_Model::getMove(i)<<" ";
    // }
    // cout<<endl;
    // cube.print();


    // Rubiks_BitBoard_Model cube;
    // unordered_map<Rubiks_BitBoard_Model, bool, HashBitBoard> mp1;
    // cube.randomShuffleCube(8);
    //
    // mp1[cube] = true;
    // if (mp1[cube]) cout << "Cube is present\n";
    // else cout << "Cube is not present\n";


    //DFS
    // Rubiks_3D_Model cube;
    // Rubiks_1D_Model cube;
    // cube.print();
    //
    // // Apply some moves to scramble
    // cube.move(GenericRubiksCube::MOVE::L);
    // cube.move(GenericRubiksCube::MOVE::B);
    // cube.move(GenericRubiksCube::MOVE::U);
    // // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // // cout << "\n";
    // cout<<"After Scramble"<<endl;
    // cube.print();
    //
    //
    // // Set max depth (try small value like 5 or 6)
    // int max_depth = 7;
    //
    // // Create solver object
    // DFS_Solver solver(&cube, max_depth);
    //
    // // Solve
    // vector<GenericRubiksCube::MOVE> solution = solver.solve();
    //
    // // Output the moves
    // if (solution.empty()) {
    //     cout << "No solution found within depth " << max_depth << endl;
    // } else {
    //     cout << "Solution found in " << solution.size() << " moves:\n";
    //     for (auto m : solution) {
    //         cout << GenericRubiksCube::getMove(m) << " ";
    //     }
    //     cout << endl;
    // }


    //BFS
    Rubiks_BitBoard_Model cube;
    cube.print();
    // cube.move(GenericRubiksCube::MOVE::L);
    // cube.move(GenericRubiksCube::MOVE::B);
    // cube.move(GenericRubiksCube::MOVE::U);
    vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(4);
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cout<<"After Scramble"<<endl;
    cube.print();

    BFS_Solver<Rubiks_BitBoard_Model,HashBitBoard> solver(cube);
    vector<GenericRubiksCube::MOVE> moves = solver.solve();
    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";

    return 0;
}
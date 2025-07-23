#include <bits/stdc++.h>
using namespace std;

// #include "Models/Rubiks_3D_Model.cpp"
// #include "Models/Rubiks_1D_Model.cpp"
#include "Models/Rubiks_BitBoard_Model.cpp"

#include "Solvers/DFS_Solver.h"
#include "Solvers/BFS_Solver.h"
#include "Solvers/IDDFS_Solver.h"
#include "Solvers/IDAstar_Solver.h"

#include "Pattern_Database/Corner_Pattern_Database.h"
// #include "Pattern_Database/Corner_DB_Maker.h"
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
    // Rubiks_BitBoard_Model cube;
    // // Rubiks_1D_Model cube;
    // cube.print();
    //
    // // Apply some moves to scramble
    // // cube.move(GenericRubiksCube::MOVE::L);
    // // cube.move(GenericRubiksCube::MOVE::B);
    // // cube.move(GenericRubiksCube::MOVE::U);
    // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
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


    // //BFS
    // Rubiks_BitBoard_Model cube;
    // // Rubiks_1D_Model cube;
    // cube.print();
    // // cube.move(GenericRubiksCube::MOVE::L);
    // // cube.move(GenericRubiksCube::MOVE::B);
    // // cube.move(GenericRubiksCube::MOVE::U);
    // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cout<<"After Scramble"<<endl;
    // cube.print();
    //
    // BFS_Solver<Rubiks_BitBoard_Model,HashBitBoard> solver(cube);
    // vector<GenericRubiksCube::MOVE> moves = solver.solve();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";



    // //IDDFS_Solver
    // Rubiks_BitBoard_Model cube;
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(6);
    // for (auto i : moves) {
    //     cout<<GenericRubiksCube::getMove(i)<<" ";
    // }
    // cout<<endl;
    //
    // cube.print();
    //
    // IDDFS_Solver solver(&cube,7);
    // vector<GenericRubiksCube::MOVE> solved_moves= solver.solve();
    // for (auto i : solved_moves) {
    //     cout<<GenericRubiksCube::getMove(i)<<" ";
    // }



    // //IDAstar_Solver
    // Rubiks_BitBoard_Model cube;
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(6);
    // for (auto i : moves) {
    //     cout<<GenericRubiksCube::getMove(i)<<" ";
    // }
    // cout<<endl;
    // cube.print();
    //
    // IDAstar_Solver<Rubiks_BitBoard_Model,HashBitBoard> solver(cube);
    //
    // vector<GenericRubiksCube::MOVE> solved_moves= solver.solve();
    // for (auto i : solved_moves) {
    //     cout<<GenericRubiksCube::getMove(i)<<" ";
    // }



    // //Corners_check
    // Rubiks_BitBoard_Model cube;
    // cube.l();
    // cube.r();
    // cube.print();
    //
    // for (int i = 0;i<8;i++) {
    //     cout<<"CORNER "<<i<<endl;
    //
    //     string ans = cube.getCornerColorString(i);
    //     cout<<"COLOR "<<ans<<endl;
    //
    //     int cidx = cube.getCornerIndex(i);
    //     cout<<"INDEX "<<cidx<<endl;
    //
    //     int cori = cube.getCornerOrientation(i);
    //     cout<<"ORIENTATION "<<cori<<endl;
    //
    //     cout<<endl;
    //
    // }

    // Rubiks_BitBoard_Model cube;
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(6);
    //
    // Corner_Pattern_Database cd;
    // uint32_t rank = cd.getDatabaseIndex(cube);
    // cout<<rank<<endl;



    string fileName = "..\\Database\\cornerDepth.txt";

    // Corner_Pattern_Database cornerDB;
    // cornerDB.fromFile(fileName);
    // Rubiks_BitBoard_Model cube;
    // cube.print();
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(8);
    // for (auto i : moves) {
    //     cout<<cube.getMove(i)<<" ";
    // }
    // cout<<endl;
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";



    // cornerDB.setNumMoves(cube, 5);
    //
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    // cube.randomShuffleCube(1);
    // cube.print();
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    //
    // cornerDB.setNumMoves(cube, 6);
    //
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";








    // // Create Corner Database
    // Corner_DB_Maker dbMaker(fileName, 0x66); //here 66 is the "nibble 6 and nibble 6" which indicates the underestimate for the cube whose depth is >= 6
    // dbMaker.bfsAndStore();


    Rubiks_BitBoard_Model cube;
    cube.print();

    auto shuffleMoves = cube.randomShuffleCube(10);
    cube.print();
    for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    cout << "\n";

    IDAstar_Solver<Rubiks_BitBoard_Model, HashBitBoard> idaStarSolver(cube, fileName);
    auto moves = idaStarSolver.solve();

    for (auto move: moves) cout << cube.getMove(move) << " ";
    cout << "\n";


    return 0;
}
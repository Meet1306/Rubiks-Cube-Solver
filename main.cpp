#include <bits/stdc++.h>
using namespace std;

// #include "Models/Rubiks_3D_Model.cpp"
// #include "Models/Rubiks_1D_Model.cpp"
#include "Models/Rubiks_BitBoard_Model.cpp"
int main() {
    // Rubiks_3D_Model cube;
    // cube.move(GenericRubiksCube::MOVE::R);
    // cube.print();
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


    Rubiks_BitBoard_Model cube;
    cube.f();
    cube.print();

    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(10);
    // for (auto i: moves)
    // {
    //     cout<<Rubiks_BitBoard_Model::getMove(i)<<" ";
    // }
    // cout<<endl;
    // cube.print();
    return 0;
}
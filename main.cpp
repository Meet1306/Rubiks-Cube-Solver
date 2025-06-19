#include <bits/stdc++.h>
using namespace std;

#include "Models/Rubiks_3D_Model.cpp"

int main() {
    Rubiks_3D_Model cube;
    cube.move(GenericRubiksCube::MOVE::R);
    cube.print();
    // vector<GenericRubiksCube::MOVE> moves = cube.randomShuffleCube(10);
    // for (auto i : moves)
    // {
    //     cout<<GenericRubiksCube::getMove(i)<<" ";
    // }
    // cout<<endl;
    // cube.print();




    return 0;
}
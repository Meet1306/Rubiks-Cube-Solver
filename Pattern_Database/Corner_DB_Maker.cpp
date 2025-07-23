//
// Created by meet1 on 19-07-2025.
//

#include "Corner_DB_Maker.h"

#include <bits/stdc++.h>
using namespace std;

Corner_DB_Maker::Corner_DB_Maker(string _fileName) {
    fileName = _fileName;
}

Corner_DB_Maker::Corner_DB_Maker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = Corner_Pattern_Database(init_val);
}

bool Corner_DB_Maker::bfsAndStore() {
    Rubiks_BitBoard_Model cube;
    queue<Rubiks_BitBoard_Model> q;
    q.push(cube);  //solved state
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    while (!q.empty()) {
        int n = q.size();
        curr_depth++;
        if (curr_depth == 6) break;
        for (int counter = 0; counter < n; counter++) {
            Rubiks_BitBoard_Model node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = GenericRubiksCube::MOVE(i);
                node.move(curr_move);
                if ((int) cornerDB.getNumMoves(node) > curr_depth) {
                    cornerDB.setNumMoves(node, curr_depth);
                    q.push(node);
                }
                node.invertMove(curr_move);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}
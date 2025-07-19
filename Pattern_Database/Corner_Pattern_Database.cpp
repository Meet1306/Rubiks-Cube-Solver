//
// Created by meet1 on 19-07-2025.
//

#include "Corner_Pattern_Database.h"
Corner_Pattern_Database::Corner_Pattern_Database() : Pattern_Database(100179840) {}

Corner_Pattern_Database::Corner_Pattern_Database(uint8_t init_val) : Pattern_Database(100179840, init_val) {}

uint32_t Corner_Pattern_Database::getDatabaseIndex(const GenericRubiksCube &cube) const {
    array<uint8_t, 8> cornerPermutation =
            {
        cube.getCornerIndex(0),
        cube.getCornerIndex(1),
        cube.getCornerIndex(2),
        cube.getCornerIndex(3),
        cube.getCornerIndex(4),
        cube.getCornerIndex(5),
        cube.getCornerIndex(6),
        cube.getCornerIndex(7),
        };

    uint32_t rank = this->permIndexer.rank(cornerPermutation);

    array<uint8_t, 7> cornerOrientations = {
        cube.getCornerOrientation(0),
        cube.getCornerOrientation(1),
        cube.getCornerOrientation(2),
        cube.getCornerOrientation(3),
        cube.getCornerOrientation(4),
        cube.getCornerOrientation(5),
        cube.getCornerOrientation(6),
    };

    uint32_t orientationNum =
            cornerOrientations[0] * 729 +
            cornerOrientations[1] * 243 +
            cornerOrientations[2] * 81 +
            cornerOrientations[3] * 27 +
            cornerOrientations[4] * 9 +
            cornerOrientations[5] * 3 +
            cornerOrientations[6];

    return (rank * 2187) + orientationNum;
}
//
// Created by ahazi on 1/8/2024.
//

#ifndef SNAKE_CUBE_PUZZLE_GRIDPOSITION_H
#define SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

#include <vector>
#include <array>

#include "snake_cube_solver.h"

using namespace std;

class GridPosition {
public:
    array<int, 3> position;
    explicit GridPosition(array<int, 3> position, int sideLength, cube* spaceGrid);
    bool advancePosition(vector<int> direction);
    void retracePosition(vector<int> direction);
    ~GridPosition();
    bool operator==(const GridPosition& otherPosition) const;
    int operator[](int coordinate) const;
private:
    int sideLength;
    cube spaceGrid;
    bool checkValidity();
};


#endif //SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

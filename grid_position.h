//
// Created by ahazi on 1/8/2024.
//
#pragma once

#ifndef SNAKE_CUBE_PUZZLE_GRIDPOSITION_H
#define SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

#include <tuple>
#include <list>
#include <array>
#include <vector>

using namespace std;

typedef unsigned  int uint;
typedef vector<vector<vector<uint>>> cube;


class GridPosition {
public:
    explicit GridPosition(const array<int, 3> &positionInp, int sideLengthInp);
    bool advancePosition(vector<int> direction, int steps, cube &spaceGrid);
    void retracePosition(vector<int> direction, int steps, cube &spaceGrid, bool fixGrid = true);
    ~GridPosition();
    bool operator==(const GridPosition& otherPosition) const;
    int operator[](int coordinate) const;
private:
    array<int, 3> position;
    int sideLength;
    bool checkValidity(cube &spaceGrid);
};


#endif //SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

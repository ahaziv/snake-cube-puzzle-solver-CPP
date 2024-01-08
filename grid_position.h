//
// Created by ahazi on 1/8/2024.
//

#ifndef SNAKE_CUBE_PUZZLE_GRIDPOSITION_H
#define SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

#include <vector>
#include <array>

using namespace std;

class GridPosition {
public:
    array<int, 3> position;
    explicit GridPosition(array<int, 3> position, int sideLength);
    void advancePosition(vector<int> direction);
    void retracePosition(vector<int> direction);
    bool checkValidity();
    ~GridPosition();
    bool operator==(const GridPosition& otherPosition) const;
    int operator[](int coordinate) const;
private:
    int sideLength;
};


#endif //SNAKE_CUBE_PUZZLE_GRIDPOSITION_H

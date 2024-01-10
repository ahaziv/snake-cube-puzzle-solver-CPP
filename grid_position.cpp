//
// Created by ahazi on 1/8/2024.
//

#include "grid_position.h"

GridPosition::GridPosition(const array<int, 3>& positionInp, int sideLengthInp){
    sideLength = sideLengthInp;
    position = {positionInp[0], positionInp[1], positionInp[2]};
}

GridPosition::~GridPosition() = default;

bool GridPosition::advancePosition(vector<int> direction, int steps, cube &spaceGrid) {
    int gridValue = spaceGrid[position[0]][position[1]][position[2]];
    int successfulSteps = 0;
    bool validStep;
    for (int step = 0; step < steps; step++){
        for(int i = 0; i < 3; i++){
            position[i] += direction[i];
        }
        validStep = checkValidity(spaceGrid);
        if (!validStep){
            break;
        }
        successfulSteps += 1;
        spaceGrid[position[0]][position[1]][position[2]] = gridValue + successfulSteps;
    }
    if (!validStep){
        retracePosition(direction, 1, spaceGrid, false);
        retracePosition(direction, successfulSteps, spaceGrid, true);
    }
    return validStep;
}

void GridPosition::retracePosition(vector<int> direction, int steps, cube &spaceGrid, bool fixGrid) {
    for (int step = 0; step < steps; step++){
        if (fixGrid){
            spaceGrid[position[0]][position[1]][position[2]] = 0;
        }
        for(int i = 0; i < 3; i++){
            position[i] -= direction[i];
        }
    }
}

bool GridPosition::checkValidity(cube &spaceGrid) {
    for(int i = 0; i < 3; i++){
        if (position[i] < 0 or position[i] >= sideLength){
            return false;
        }
    }
    if (spaceGrid[position[0]][position[1]][position[2]] != 0){
        return false;
    }
    return true;
}

bool GridPosition::operator==(const GridPosition& otherPosition) const{
    return position == otherPosition.position;
}

int GridPosition::operator[](int coordinate) const{
    return position[coordinate];
}
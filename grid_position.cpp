//
// Created by ahazi on 1/8/2024.
//

#include "grid_position.h"

GridPosition::GridPosition(array<int, 3> position, int sideLength, cube* spaceGrid){
    this-> sideLength = sideLength;
    this-> spaceGrid = *spaceGrid;          // TODO - check if this actually creates a seperate cube or just points to origin
    for(int i = 0; i < 3; i++){
        this->position[i] = position[i];
    }
}

GridPosition::~GridPosition() = default;

bool GridPosition::advancePosition(vector<int> direction) {
    int gridValue = spaceGrid[position[0]][position[1]][position[2]];
    for(int i = 0; i < 3; i++){
        this->position[i] += direction[i];
    }
    bool validStep = checkValidity();
    if (validStep){
        spaceGrid[position[0]][position[1]][position[2]] = gridValue;
    }
    else{
        retracePosition(direction);
    }
}

void GridPosition::retracePosition(vector<int> direction) {
    for(int i = 0; i < 3; i++){
        this->position[i] -= direction[i];
    }
}
bool GridPosition::checkValidity() {
    for(int i = 0; i < 3; i++){
        if ((this->position[i] < 0)
             or (this->position[i] >= this->sideLength)
             or spaceGrid[position[0]][position[1]][position[2]] != 0){
            return false;
        }
    }
    return true;
}

bool GridPosition::operator==(const GridPosition& otherPosition) const{
    return this->position == otherPosition.position;
}

int GridPosition::operator[](int coordinate) const{
    return this->position[coordinate];
}
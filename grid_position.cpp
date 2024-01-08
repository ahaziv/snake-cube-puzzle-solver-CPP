//
// Created by ahazi on 1/8/2024.
//

#include "grid_position.h"

GridPosition::GridPosition(array<int, 3> position, int sideLength){
    this->sideLength = sideLength;
    for(int i = 0; i < 3; i++){
        this->position[i] = position[i];
    }
}

GridPosition::~GridPosition() {}

void GridPosition::advancePosition(vector<int> direction) {
    for(int i = 0; i < 3; i++){
        this->position[i] += direction[i];
    }
}
void GridPosition::retracePosition(vector<int> direction) {
    for(int i = 0; i < 3; i++){
        this->position[i] -= direction[i];
    }
}
bool GridPosition::checkValidity() {
    for(int i = 0; i < 3; i++){
        if ((this->position[i] < 0) or (this->position[i] >= this->sideLength)){
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
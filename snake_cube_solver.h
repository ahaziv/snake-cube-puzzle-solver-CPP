//
// Created by ahazi on 1/1/2024.
//
#pragma once

#ifndef SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H
#define SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H

#include <memory>

#include "connectivity_graph.h"
#include "grid_position.h"

using namespace std;

tuple<bool, int> solveCube(cube& spaceGrid, list<int> snakeRemainder, GridPosition startPosition,
                           vector<int> direction, BaseGraph* graph);

tuple<cube, bool, int> solveSnake(list<int>& snake, int sideLength, const list< array<int, 3>> &startingPositions,
                                  bool checkConnectivity);

#endif //SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H

//
// Created by ahazi on 1/1/2024.
//
#pragma once

#ifndef SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H
#define SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H

#include <tuple>
#include <list>
#include <array>
#include <vector>
#include "connectivity_graph.h"
#include "grid_position.h"

using namespace std;

typedef unsigned  int uint;
typedef vector<vector<vector<uint>>> cube;

tuple<bool, int> solveCube(cube& spacegrid, list<int> snakeRemainder, GridPosition startPosition,
                           vector<int> direction, BaseGraph &connectivityGraph);

tuple<cube, bool, int> solveSnake(list<int>& snake, int sideLength, list< GridPosition > startingPositions,
                                  bool checkConnectivity);

#endif //SNAKE_CUBE_PUZZLE_SNAKE_CUBE_SOLVER_H

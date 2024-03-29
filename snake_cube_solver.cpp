//
// Created by ahazi on 1/1/2024.
//

#include <tuple>
#include <list>
#include <vector>

#include "connectivity_graph.h"
#include "snake_cube_solver.h"
#include "grid_position.h"

using namespace std;

vector<vector<int>> perpendicularDirections(vector<int> &direction){
    // get the next possible directions according to the physical constraints
    vector<vector<int>>  allDirections = {{1, 0, 0},{-1, 0, 0},
                                          {0, 1, 0}, {0, -1, 0},
                                          {0, 0, 1}, {0, 0, -1}};
    if (direction[0] != 0){
        vector<vector<int>> outputDirections = {allDirections[2], allDirections[3], allDirections[4], allDirections[5]};
        return outputDirections;
    }
    if (direction[1] != 0){
        vector<vector<int>> outputDirections = {allDirections[0], allDirections[1], allDirections[4], allDirections[5]};
        return outputDirections;
    }
    if (direction[1] != 0){
        vector<vector<int>> outputDirections = {allDirections[0], allDirections[1], allDirections[2], allDirections[3]};
        return outputDirections;
    }
    else{
        return allDirections;
    }
}


tuple<bool, int> solveCube(cube& spaceGrid, list<int> snakeRemainder, GridPosition pos, vector<int> prevDirection,
                           BaseGraph* graph){
    //  This recursive function tries filling the next link of the snake.
    //  If it fails in all directions - it returns False
    //  If no links remain (stopping condition) if returns the solution.
    //  If it succeeds on one side it recursively attempts the next step (the return value will determine if it's a success)
    //  :param spaceGrid: An n*n*n array representing the space
    //  :param snake_remainder: a list of numbers representing the snake's link sizes
    //  :param prev_position: the cube-before-last position
    //  :param start_position: the last cube position
    //  :param step_num: the number of steps required to reach a solution
    //  :param connectivity_graph: a connectivity graph, if added stops solution if solution reaches discontinuity
    if (snakeRemainder.empty()){
        tuple<bool, int> solution(true, 1);
        return solution;
    }
    vector<vector<int>> dirGrid = perpendicularDirections(prevDirection);
    uint steps = 0;
    for (const vector<int>& direction: dirGrid) {
        bool success = true;
        steps += snakeRemainder.front();
        success = pos.advancePosition(direction, snakeRemainder.front(), spaceGrid, graph);
        if (not success){continue;}
        success = graph->isConnected();
        if (!success){
            int pause = 1;
        }
        if (success) {
            int tempSteps;
            list<int> recursionSnake = snakeRemainder;
            recursionSnake.pop_front();
            tie(success, tempSteps) = solveCube(spaceGrid, recursionSnake, pos, direction, graph);
            steps += tempSteps;
            if (success){
                return make_tuple(true, steps);
            }
        }
        if (!success){          // if solution has failed delete the filled spaces in spaceGrid and fix connectivityGraph back to the previous position
            pos.retracePosition(direction, snakeRemainder.front(), spaceGrid, graph);
        }
    }
    return make_tuple(false, steps);
}


tuple<cube, bool, int> solveSnake(list<int>& snake, int sideLength, const list< array<int, 3>> &startingPositions,
                                  bool checkConnectivity){
    // attempts solving the puzzle from different starting positions, if no positions returns a valid solution return false
    cube spaceGrid(sideLength, vector<vector<uint>>(sideLength, vector<uint>(sideLength)));
    *snake.begin() -= 1;
    int step_num = 0;
    for (const auto& position : startingPositions) {
        // initialize spaceGrid to zeros
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                for (int k = 0; k < sideLength; k++) {
                    spaceGrid[i][j][k] = 0;
                }
            }
        }
        spaceGrid[position[0]][position[1]][position[2]] = 1;
        unique_ptr<BaseGraph> myGraph;
        if (checkConnectivity){
            myGraph = make_unique<ConnectivityGraph>(sideLength);
        } else{
            myGraph = make_unique<EmptyGraph>();
        }
        tuple coordinate(position[0], position[1], position[2]);
        myGraph->deleteNode(coordinate);

        bool isSolved;
        int steps;
        vector<int> direction({0, 0, 0});
        GridPosition gridPosition = GridPosition(position, sideLength);
        tie(isSolved, steps) = solveCube(spaceGrid, snake, gridPosition, direction, myGraph.get());
        step_num += steps;
        if (isSolved) {
            return make_tuple(spaceGrid, true, step_num);
        }
    }
    return make_tuple(spaceGrid, false, step_num);
}

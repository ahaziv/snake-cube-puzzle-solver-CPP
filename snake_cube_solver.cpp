//
// Created by ahazi on 1/1/2024.
//

#include <tuple>
#include <list>
#include <array>
#include <vector>

#include "connectivity_graph.h"
#include "snake_cube_solver.h"

using namespace std;

tuple<bool, int> solveCube(cube& spacegrid, list<int> snakeRemainder, array<int, 3> startPosition,
                           array<int, 3> prevPosition, BaseGraph &connectivityGraph){
    //  This recursive function tries filling the next link of the snake.
    //  If it fails in all directions - it returns False
    //  If no links remain (stopping condition) if returns the solution.
    //  If it succeeds on one side it recursively attempts the next step (the return value will determine if it's a success)
    //  :param spacegrid: An n*n*n array representing the space
    //  :param snake_remainder: a list of numbers representing the snake's link sizes
    //  :param prev_position: the cube-before-last position
    //  :param start_position: the last cube position
    //  :param step_num: the number of steps required to reach a solution
    //  :param connectivity_graph: a connectivity graph, if added stops solution if solution reaches discontinuity
    if (snakeRemainder.empty()){
        tuple<bool, int> solution(true, 1);
        return solution;
    }
    else{
        tuple<bool, int> solution(false, 1);        // TODO - implement
        return solution;
    }
}


tuple<cube, bool, int> solveSnake(list<int>& snake, int sideLength, const list< array<int, 3> > &startingPositions, bool checkConnectivity){
    // attempts solving the puzzle from different starting positions, if no positions returns a valid solution return false
    static cube spaceGrid(sideLength, vector<vector<uint>>(sideLength, vector<uint>(sideLength)));
    *snake.begin() -= 1;                                                     // TODO - check this line does what I expect it does
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
        EmptyGraph connectivityGraph = EmptyGraph();
        if (checkConnectivity){
            ConnectivityGraph connectivityGraph = ConnectivityGraph(sideLength);
        }
        std::tuple coordinate(position[0], position[1], position[2]);
        connectivityGraph.deleteNode(coordinate);

        bool isSolved;
        int steps;
        tie(isSolved, steps) = solveCube(spaceGrid, snake, position,
                                                   position, connectivityGraph);
        step_num += steps;
        if (isSolved) {
            return make_tuple(spaceGrid, true, step_num);
        }
    }
    return make_tuple(spaceGrid, false, step_num);
}

#include <iostream>
#include <list>
#include <numeric>
#include <cmath>
#include <chrono>
#include <array>

#include "snake_cube_solver.h"

int main() {
    const uint sideLength = 3;
    const bool checkConnectivity = false;
    list<int> snakeLinks;
    switch (sideLength){
        case 2:
            snakeLinks = {2, 1, 1, 1, 1, 1, 1};
            break;
        case 3:
            snakeLinks = {3, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2};
            break;
        case 4:
            snakeLinks = {2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 1, 1, 1, 3, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1,
                          1, 1, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 2, 1, 2};
            break;
        default:
            std::cout << "Illegal sideLength value:" << sideLength <<", please select values between 2 and 4"<< std::endl;
            return 1;
        }


    int cubeNumber = accumulate(snakeLinks.begin(), snakeLinks.end(), 0);
    cout << "number of cubes: " << cubeNumber << endl;
    if (cubeNumber != pow(sideLength, 3)){
        cout << "wrong parameters, please check the snake array/side size" << endl;
        return 1;
    }
    else{
        cout << "Valid cube, proceeding to calculate solution" << endl;
    };

    const list< array<int, 3>> startingPositions = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    auto start = chrono::high_resolution_clock::now();
    cube solutionGrid;
    bool isSolved;
    uint stepNum;
    tie(solutionGrid, isSolved, stepNum) = solveSnake(snakeLinks, sideLength, startingPositions, checkConnectivity);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    if (isSolved){
        cout << "A solution have been reached, steps performed: " << stepNum  << endl << "Solution: " << endl;
        for (int i = 0; i < sideLength; i++) {
            cout << "Layer " << i << ":";
            for (int j = 0; j < sideLength; j++) {
                cout << endl;
                for (int k = 0; k < sideLength; k++) {
                    cout << solutionGrid[i][j][k];
                }
            }
        }
    }
    else{cout << "No solution have been reached, steps performed: " << stepNum << endl;}
    cout << "running time: " << duration.count() << " microseconds" << endl;
}

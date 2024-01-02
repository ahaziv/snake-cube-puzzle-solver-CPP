#include <iostream>
#include <list>
#include <numeric>
#include <cmath>
#include <chrono>
#include <array>

int main(int sideLength = 3) {
    std::list<int> snake_links;
    if (sideLength == 2){
        snake_links = {2, 1, 1, 1, 1, 1, 1};
    }
    else if (sideLength == 3){
        snake_links = {3, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2};
    }
    else if (sideLength == 4){
        snake_links = {2, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 3, 1, 1, 1, 3, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1,
                       1, 1, 1, 2, 1, 2, 1, 2, 1, 3, 1, 1, 2, 1, 2};
    }
    else {
        std::cout << "Illegal sideLength value:" << sideLength <<", please select values between 2 and 4"<< std::endl;
        return 1;
    };

    int cubeNumber = std::accumulate(snake_links.begin(), snake_links.end(), 0);
    std::cout << "number of cubes: " << cubeNumber << std::endl;
    if (cubeNumber != std::pow(sideLength, 3)){
        std::cout << "wrong parameters, please check the snake array/side size" << std::endl;
        return 1;
    }
    else{
        std::cout << "Valid cube, proceeding to calculate solution" << std::endl;
    };

    const std::list< std::array<int, 3>> starting_positions = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    auto start = std::chrono::high_resolution_clock::now();
//    solution_grid, step_num = solve_snake(snake, side_size, starting_positions, check_connectivity=False)
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "running time: " << duration.count() << " microseconds" << std::endl;
//    if solution_grid is not False:
//    print('solution has been reached!')
//    print(f'complexity report:\nproblem complexity: 4^{len(snake)} ({4**len(snake)} steps)\nsteps performed: {step_num}')
//    present_solution(solution_grid)
//    else:
//    print(f'no solution found, steps performed: {step_num}')
}

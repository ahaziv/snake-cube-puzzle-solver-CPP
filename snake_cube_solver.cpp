//
// Created by ahazi on 1/1/2024.
//
#include <tuple>
#include <list>
#include <array>

std::tuple<bool, int>  solve_cube(std::array<int, 3> spacegrid, std::list<int> snakeRemainder,
                                  std::array<int, 3> start_position, std::array<int, 3> prev_position,
    connectivity_graph: ConnectivityGraph = None):
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
    if (snake_remainder.){
        return <spacegrid, 1>
    }
    else


// TODO - see how can we return a tuple containing a dynamic value (either an array or a boolean)
std::tuple<bool, int> solve_snake(int snake[], int sideLength, std::list< std::array<int, 3> > startingPositions, bool checkConnectivity){
    // attempts solving the puzzle from different starting positions, if no positions returns a valid solution return false
    int spaceGrid[sideLength][sideLength][sideLength];
    for (int i = 0; i < sideLength; i++){
        for (int j = 0; j < sideLength; j++){
            for (int k = 0; k < sideLength; k++){
                spaceGrid[i][j][k] = 0;
            }
        }
    }
    snake[0] -= 1;
    int step_num = 0;
    for (const auto& position : startingPositions) {        // TODO - better understand this line
        // initialize spaceGrid to zeros
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                for (int k = 0; k < sideLength; k++) {
                    spaceGrid[i][j][k] = 0;
                }
            }
        }
        spaceGrid[position[0]][position[1]][position[2]] = 1;
        if (checkConnectivity) {
           connectivityGraph = ConnectivityGraph(side_size)
           connectivity_graph.delete_node((position[0], position[1], position[2]))
        }
        else {connectivity_graph = null}

        solution, steps = solve_cube(spaceGrid, snake, position, None, connectivity_graph);
        step_num += steps;
        if solution is not False:
            return tuple <bool, int> = <solution, step_num>
        return tuple <bool, int> false, step_num
    }
}

//
// Created by ahazi on 1/2/2024.

#include <map>
#include <tuple>
#include <list>
#include <array>
#include "connectivity_graph.h"

class ConnectivityGraph {
private:
    int sideLength;
    std::map<std::tuple<int, int, int>, std::list<std::tuple<int, int, int>>> graph;
    const int neighborNodeBase[6][3] = {{-1, 0, 0}, {1, 0, 0},
                                        {0, -1, 0}, {0, 1, 0},
                                        {0, 0, -1}, {0, 0, 1}};

    std::list<std::tuple<int, int, int>> getNeighborNodes(std::tuple<int, int, int> node){
        std::list<std::tuple<int, int, int>> neighborNodes{(1, 1, 1)};
        return neighborNodes;
    }

public:
    ConnectivityGraph(int sideLength){
        this->sideLength = sideLength;
        for (int i=0; i<sideLength; i++){
            for (int j=0; j<sideLength; j++){
                for (int k=0; k<sideLength; k++) {
                    std::tuple index(i, j, k);
                    this->graph[index] = this->getNeighborNodes(index);
                }
            }
        }
    }

};

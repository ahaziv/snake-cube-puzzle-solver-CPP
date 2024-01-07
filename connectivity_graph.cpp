//
// Created by ahazi on 1/2/2024.

#include <map>
#include <tuple>
#include <set>

#include "connectivity_graph.h"


using namespace std;

BaseGraph::BaseGraph() {}
BaseGraph::~BaseGraph() {}

void EmptyGraph::deleteNode(tuple<int, int, int> node){}
void EmptyGraph::addNode(tuple<int, int, int> node){}
bool EmptyGraph::isConnected(){
    return true;
}

ConnectivityGraph::ConnectivityGraph(int sideLength){         // TODO - why add the explicit here?
    this->sideLength = sideLength;
    for (int i=0; i<sideLength; i++){
        for (int j=0; j<sideLength; j++){
            for (int k=0; k<sideLength; k++) {
                tuple index(i, j, k);
                this->graph[index] = this->getNeighborNodes(index);
            }
        }
    }
}

// ConnectivityGraph implementation
set<tuple<int, int, int>> ConnectivityGraph::getNeighborNodes(tuple<int, int, int> node){
    set<tuple<int, int, int>> neighborNodes({});      // TODO - implement
    for (const auto& neighbor : this->neighborNodeBase) {
        if (0 <= get<0>(node) + neighbor[0] <= this->sideLength
        and 0 <= get<1>(node) + neighbor[1] <= this->sideLength
        and 0 <= get<2>(node) + neighbor[2] <= this->sideLength){
            tuple<int, int ,int> newNeighbor(get<0>(node) + neighbor[0],
                                             get<1>(node) + neighbor[1],
                                             get<2>(node) + neighbor[2]);
            neighborNodes.insert(newNeighbor);
        }
    }
    return neighborNodes;
}


void ConnectivityGraph::deleteNode(tuple<int, int, int> node){
    set<tuple<int, int, int>> neighbors = this->graph[node];
    this->graph.erase(node);
    for (const auto& neighbor : neighbors) {
        this->graph[neighbor].erase(neighbor);
    }

}

void ConnectivityGraph::addNode(tuple<int, int, int> node){

}

bool ConnectivityGraph::isConnected(){
    return true;      // TODO - implement
}

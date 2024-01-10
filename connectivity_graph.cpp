//
// Created by ahazi on 1/2/2024.

#include <tuple>
#include <set>
#include <list>

#include "connectivity_graph.h"


using namespace std;

BaseGraph::BaseGraph() {}
BaseGraph::~BaseGraph() {}

void EmptyGraph::deleteNode(tuple<int, int, int> node){}
void EmptyGraph::addNode(tuple<int, int, int> node){}
bool EmptyGraph::isConnected(){
    return true;
}

ConnectivityGraph::ConnectivityGraph(int sideLengthInp){
    sideLength = sideLengthInp;
    for (int i=0; i<sideLength; i++){
        for (int j=0; j<sideLength; j++){
            for (int k=0; k<sideLength; k++) {
                tuple index(i, j, k);
                graph[index] = getNeighborNodes(index);
            }
        }
    }
}

// ConnectivityGraph implementation
set<tuple<int, int, int>> ConnectivityGraph::getNeighborNodes(tuple<int, int, int> node){
    set<tuple<int, int, int>> neighborNodes({});
    for (const auto& neighbor : neighborNodeBase) {
        if (0 <= get<0>(node) + neighbor[0] <= sideLength
        and 0 <= get<1>(node) + neighbor[1] <= sideLength
        and 0 <= get<2>(node) + neighbor[2] <= sideLength){
            tuple<int, int ,int> newNeighbor(get<0>(node) + neighbor[0],
                                             get<1>(node) + neighbor[1],
                                             get<2>(node) + neighbor[2]);
            neighborNodes.insert(newNeighbor);
        }
    }
    return neighborNodes;
}


void ConnectivityGraph::deleteNode(tuple<int, int, int> node){
    set<tuple<int, int, int>> neighbors = graph[node];
    graph.erase(node);
    for (const auto& neighbor : neighbors) {
        graph[neighbor].erase(neighbor);
    }

}

void ConnectivityGraph::addNode(tuple<int, int, int> node){
    graph[node] = getNeighborNodes(node);
    for (const tuple<int, int, int>& neighbor: graph[node]){
        if (graph.find(neighbor) == graph.end()){
            graph.erase(neighbor);
        }
    }
}

bool ConnectivityGraph::isConnected(){
    // uses BFS to check for graph connectivity
    set<tuple<int, int, int>> nonTestedNodes = {};
    for (auto & it : graph){
        nonTestedNodes.insert(it.first);                // TODO - make sure this indeed creates a deep copy
    }
    list<tuple<int, int, int>> queue;
    if (!nonTestedNodes.empty()) {
        auto it = nonTestedNodes.begin();
        queue.push_back(*it);
        nonTestedNodes.erase(it);
    }
    while (true){
        if (nonTestedNodes.empty()){
            return true;
        }
        for (auto & node: graph[queue.front()]){
            if (nonTestedNodes.find(node) != nonTestedNodes.end()){
                queue.push_back(node);
                nonTestedNodes.erase(node);
            }
        }
        queue.pop_front();
        if (queue.empty()){
            return false;
        }

    }
}

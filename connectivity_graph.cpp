//
// Created by ahazi on 1/2/2024.

#include <tuple>
#include <set>
#include <list>
#include <cmath>

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
    edges = vector<vector<int>>(pow(sideLength,3), vector<int>(pow(sideLength,3)));
    for (int i=0; i < pow(sideLength,3); i++){
        for (int j=0; j < pow(sideLength,3); j++){
            edges[i][j] = 0;
        }
    }

    for (int i=0; i<sideLength; i++){
        for (int j=0; j<sideLength; j++){
            for (int k=0; k<sideLength; k++) {
                nodes.insert(indexToNum(i, j, k));
                set<int> neighbors = getNeighborNodes(make_tuple(i, j, k));
                for (int neighbor: neighbors){
                    edges[indexToNum(i, j, k)][neighbor] = 1;
                    edges[neighbor][indexToNum(i, j, k)] = 1;
                }
            }
        }
    }
}

int ConnectivityGraph::indexToNum(int i, int j, int k) const{
    return i * pow(sideLength, 2) + j * sideLength + k;
}

set<int> ConnectivityGraph::getNeighborNodes(tuple<int, int, int> node){
    set<int> neighborNodes({});
    for (const auto& neighbor : neighborNodeBase) {
        tuple<int, int ,int> newNeighbor(get<0>(node) + neighbor[0],
                                         get<1>(node) + neighbor[1],
                                         get<2>(node) + neighbor[2]);
        if (0 <= get<0>(newNeighbor) && get<0>(newNeighbor) < sideLength
         && 0 <= get<1>(newNeighbor) && get<1>(newNeighbor) < sideLength
         && 0 <= get<2>(newNeighbor) && get<2>(newNeighbor) < sideLength){
            neighborNodes.insert(indexToNum(get<0>(newNeighbor), get<1>(newNeighbor), get<2>(newNeighbor)));
        }
    }
    return neighborNodes;
}


void ConnectivityGraph::deleteNode(tuple<int, int, int> nodeIdx){
    int nodeNum = indexToNum(get<0>(nodeIdx), get<1>(nodeIdx), get<2>(nodeIdx));
    nodes.erase(nodeNum);
    for (int i = 0; i<nodes.size(); i++) {
        edges[i][nodeNum] = 0;
        edges[nodeNum][i] = 0;
    }
}

void ConnectivityGraph::addNode(tuple<int, int, int> nodeIdx){
    int nodeNum = indexToNum(get<0>(nodeIdx), get<1>(nodeIdx), get<2>(nodeIdx));
    nodes.insert(nodeNum);
    set<int> neighbors = getNeighborNodes(nodeIdx);
    for (const int& neighbor: neighbors){
        if (nodes.find(neighbor) != nodes.end()){
            edges[nodeNum][neighbor] = 1;
            edges[neighbor][nodeNum] = 1;
        }
    }
}

bool ConnectivityGraph::isConnected(){
    // uses BFS to check for graph connectivity
    set<int> nonTestedNodes = {};
    for (int node: nodes){
        nonTestedNodes.insert(node);                // TODO - make sure this indeed creates a deep copy
    }
    list<int> queue;
    if (!nonTestedNodes.empty()) {
        auto it = nonTestedNodes.begin();
        queue.push_back(*it);
        nonTestedNodes.erase(it);
    }
    while (true){
        if (nonTestedNodes.empty()){
            return true;
        }
        for (int i = 0; i < edges[queue.front()].size(); i++){
            if (edges[queue.front()][i] == 1){
                if (nonTestedNodes.find(i) != nonTestedNodes.end()){
                    queue.push_back(i);
                    nonTestedNodes.erase(i);
                }
            }
        }
        queue.pop_front();
        if (queue.empty()){
            return false;
        }

    }
}


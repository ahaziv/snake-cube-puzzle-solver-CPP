//
// Created by ahazi on 1/2/2024.
//
#pragma once
#ifndef SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H
#define SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H

#include <map>
#include <tuple>
#include <set>

using namespace std;

class BaseGraph {
public:
    BaseGraph();
    virtual void deleteNode(tuple<int, int, int> node) = 0;
    virtual void addNode(tuple<int, int, int> node) = 0;
    virtual bool isConnected() = 0;
    ~BaseGraph();
};

class EmptyGraph : public BaseGraph {
public:
    void deleteNode(tuple<int, int, int> node) override;
    void addNode(tuple<int, int, int> node) override;
    bool isConnected() override;
};

class ConnectivityGraph : public BaseGraph {
private:
    unsigned int sideLength;
    map<tuple<int, int, int>, set<tuple<int, int, int>>> graph;
    const int neighborNodeBase[6][3] = {{-1, 0, 0}, {1, 0, 0},
                                        {0, -1, 0}, {0, 1, 0},
                                        {0, 0, -1}, {0, 0, 1}};

    set<tuple<int, int, int>> getNeighborNodes(tuple<int, int, int> node);

public:
    explicit ConnectivityGraph(int sideLength);         // TODO - why add the explicit here?
    void deleteNode(tuple<int, int, int> node) override;
    void addNode(tuple<int, int, int> node) override;
    bool isConnected() override;
};

#endif //SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H

//
// Created by ahazi on 1/2/2024.
//
#pragma once
#ifndef SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H
#define SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H

#include <map>
#include <tuple>
#include <set>
#include <vector>

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
    set<int> nodes;
    vector<vector<int>> edges;
    const int neighborNodeBase[6][3] = {{-1, 0, 0}, {1, 0, 0},
                                        {0, -1, 0}, {0, 1, 0},
                                        {0, 0, -1}, {0, 0, 1}};

    set<int> getNeighborNodes(tuple<int, int, int> node);
    int indexToNum(int, int, int) const;

public:
    explicit ConnectivityGraph(int sideLength);         // TODO - why add the explicit here?
    void deleteNode(tuple<int, int, int> node) override;
    void addNode(tuple<int, int, int> node) override;
    bool isConnected() override;
};

#endif //SNAKE_CUBE_PUZZLE_CONNECTIVITY_GRAPH_H

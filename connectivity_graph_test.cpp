//
// Created by ahazi on 1/10/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <list>

#include "connectivity_graph.h"
#include "doctest/doctest/doctest.h"

using namespace std;

bool connectivityTest(list<tuple<int, int, int>> deletedNodes, int sideLength){
    ConnectivityGraph graph = ConnectivityGraph(sideLength);
    for (const auto& node: deletedNodes){
        graph.deleteNode(node);
    }
    return graph.isConnected();
}

// Test case using Doctest
TEST_CASE("No missing nodes - sanity") {
    list<tuple<int, int, int>> deletedNodes = {};
    int sideLength = 3;
    REQUIRE(connectivityTest(deletedNodes, sideLength));
}

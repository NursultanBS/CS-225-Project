#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../graphs/digraph.h"
#include "../traversals/Dijkstra.h"
#include <iostream>

using namespace std;

TEST_CASE("Dijkstra, Undirected Graph, CSV", "[valgrind][weight=1]") {
    
    vector<vector<string>> expected = {vector<string>{"0", "1", "6", "5"}, 
                                       vector<string>{"0", "1", "2", "3", "4", "5"},
                                       vector<string>{"0", "6", "5"},
                                       vector<string>{"0", "1", "5"},
                                       vector<string>{}};
    for (int i=1; i <= 5; i++) {
        string testfile = "tests/testInputDijkstra/test";
        testfile+=to_string(i);
        testfile+=".csv";
        UdGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        vector<string> distance = test.getLeastWeightedPath(nodeA, nodeB);
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("Dijkstra, Directed Graph, CSV", "[valgrind][weight=1]") {
    
    vector<vector<string>> expected = {vector<string>{"0", "1", "6", "5"},
                                       vector<string>(),
                                       vector<string>{"0", "2", "3", "4", "5"},
                                       vector<string>{"0", "1", "5"},
                                       vector<string>()};
    vector<vector<string>> expected2 = {vector<string>{"0", "1", "2", "3", "8"}};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputDijkstra/test";
        testfile+=to_string(i);
        testfile+=".csv";
        DiGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        vector<string> distance = test.getLeastWeightedPath(nodeA, nodeB);
        REQUIRE(distance == expected[i-1]);

        if (i==1) {
            nodeA = "0";
            nodeB = "8";
            vector<string> distance2 = test.getLeastWeightedPath(nodeA, nodeB);
            REQUIRE(distance2 == expected2[i-1]);
        }
    }
}

TEST_CASE("Dijkstra, Undirected Graph, TXT", "[valgrind][weight=1]") {
    
    vector<vector<string>> expected = {vector<string>(), 
                                       vector<string>{"0", "1", "2", "3", "4", "5"},
                                       vector<string>{"0", "6", "5"},
                                       vector<string>{"0", "1", "5"},
                                       vector<string>{}};
    for (int i=1; i <= 5; i++) {
        string testfile = "tests/testTXT/test";
        testfile+=to_string(i);
        testfile+=".txt";
        UdGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        vector<string> distance = test.getLeastWeightedPath(nodeA, nodeB);
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("Dijkstra, Directed Graph, TXT", "[valgrind][weight=1]") {
    
    vector<vector<string>> expected = {vector<string>(),
                                       vector<string>(),
                                       vector<string>{"0", "2", "3", "4", "5"},
                                       vector<string>{"0", "1", "5"},
                                       vector<string>()};
    vector<vector<string>> expected2 = {vector<string>()};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testTXT/test";
        testfile+=to_string(i);
        testfile+=".txt";
        DiGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        vector<string> distance = test.getLeastWeightedPath(nodeA, nodeB);
        REQUIRE(distance == expected[i-1]);

        if (i==1) {
            nodeA = "0";
            nodeB = "8";
            vector<string> distance2 = test.getLeastWeightedPath(nodeA, nodeB);
            REQUIRE(distance2 == expected2[i-1]);
        }
    }
}

TEST_CASE("Dijkstra, Directed Graph 2, CSV", "[valgrind][weight=1]") {

    vector<string> expected = {"1", "9", "10", "11", "5"};
    string testfile = "tests/testInputDijkstra/test";
    testfile+=to_string(6);
    testfile+=".csv";
    DiGraph test(testfile);
    string nodeA = "1", nodeB = "5";
    vector<string> distance = test.getLeastWeightedPath(nodeA, nodeB);
    REQUIRE(distance == expected);
}
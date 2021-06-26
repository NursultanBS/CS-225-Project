#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../graphs/digraph.h"
#include "../traversals/BFS.h"

using namespace std;

TEST_CASE("BFS, Undirected Graph, CSV", "[valgrind][weight=1]") {
    
    vector<int> expected = {-1,5,2,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputBFS/test";
        testfile+=to_string(i);
        testfile+=".csv";
        UdGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        int distance = test.getShortestDistance(nodeA, nodeB);    
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("BFS, Undirected Graph, TXT", "[valgrind][weight=1]") {
    
    vector<int> expected = {-1,5,2,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testTXT/test";
        testfile+=to_string(i);
        testfile+=".txt";
        UdGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        int distance = test.getShortestDistance(nodeA, nodeB);    
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("BFS, Directed Graph, CSV", "[valgrind][weight=1]") {
    
    vector<int> expected = {-1,-1,4,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testInputBFS/test";
        testfile+=to_string(i);
        testfile+=".csv";
        DiGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        int distance = test.getShortestDistance(nodeA, nodeB);   
        REQUIRE(distance == expected[i-1]);
    }
}

TEST_CASE("BFS, Directed Graph, TXT", "[valgrind][weight=1]") {
    
    vector<int> expected = {-1,-1,4,2,-1};
    for (int i=1; i<= 5; i++) {
        string testfile = "tests/testTXT/test";
        testfile+=to_string(i);
        testfile+=".txt";
        DiGraph test(testfile);
        string nodeA = "0", nodeB = "5";
        int distance = test.getShortestDistance(nodeA, nodeB);
        REQUIRE(distance == expected[i-1]);
    }
}
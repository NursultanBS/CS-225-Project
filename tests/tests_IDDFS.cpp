#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../graphs/digraph.h"
#include "../graphs/graph.h"
#include "../traversals/IDDFS.h"

using namespace std;

TEST_CASE("IDDFS, Undirected Graph, CSV", "[valgrind][weight=1][part=IDDFS]") {
    
    bool expected1 = false;
    bool expected2 = false;
    bool expected3 = true;
    bool expected4 = false;
    bool expected5 = true;
    string testfile = "tests/testInputDFS/test";
    testfile+=to_string(2);
    testfile+=".csv";
    UdGraph test(testfile);
    string nodeA = "0", nodeB = "5";
    string nodeC = "4", nodeD = "10";
    bool result1 = test.isReachableIDDFS(nodeA, nodeB, 1);
    bool result2 = test.isReachableIDDFS(nodeA, nodeB, 2);
    bool result3 = test.isReachableIDDFS(nodeA, nodeB, 5);
    bool result4 = test.isReachableIDDFS(nodeC, nodeD, 1);
    bool result5 = test.isReachableIDDFS(nodeC, nodeD, 6);
    REQUIRE(result1 == expected1);
    REQUIRE(result2 == expected2);
    REQUIRE(result3 == expected3);
    REQUIRE(result4 == expected4);
    REQUIRE(result5 == expected5);
}

TEST_CASE("IDDFS, Undirected Graph, TXT", "[valgrind][weight=1][part=IDDFS]") {
    
    bool expected1 = false;
    bool expected2 = false;
    bool expected3 = true;
    bool expected4 = false;
    bool expected5 = true;
    string testfile = "tests/testTXT/test";
    testfile+=to_string(2);
    testfile+=".txt";
    UdGraph test(testfile);
    string nodeA = "0", nodeB = "5";
    string nodeC = "4", nodeD = "10";
    bool result1 = test.isReachableIDDFS(nodeA, nodeB, 1);
    bool result2 = test.isReachableIDDFS(nodeA, nodeB, 2);
    bool result3 = test.isReachableIDDFS(nodeA, nodeB, 5);
    bool result4 = test.isReachableIDDFS(nodeC, nodeD, 1);
    bool result5 = test.isReachableIDDFS(nodeC, nodeD, 6);
    REQUIRE(result1 == expected1);
    REQUIRE(result2 == expected2);
    REQUIRE(result3 == expected3);
    REQUIRE(result4 == expected4);
    REQUIRE(result5 == expected5);
}

TEST_CASE("IDDFS, Undirected Graph, TXT, 2", "[valgrind][weight=1][part=IDDFS]") {
    
    bool expected1 = false;
    bool expected2 = true;
    bool expected3 = false;
    bool expected4 = true;
    string testfile = "tests/testTXT/test";
    testfile+=to_string(6);
    testfile+=".txt";
    UdGraph test(testfile);
    string nodeA = "2", nodeB = "4";
    string nodeC = "2", nodeD = "0";
    bool result1 = test.isReachableIDDFS(nodeA, nodeB, 1);
    bool result2 = test.isReachableIDDFS(nodeA, nodeB, 2);
    bool result3 = test.isReachableIDDFS(nodeC, nodeD, 0);
    bool result4 = test.isReachableIDDFS(nodeC, nodeD, 2);
    REQUIRE(result1 == expected1);
    REQUIRE(result2 == expected2);
    REQUIRE(result3 == expected3);
    REQUIRE(result4 == expected4);
}

TEST_CASE("IDDFS, Directed Graph, CSV", "[valgrind][weight=1][part=IDDFS]") {
    
    bool expected1 = false;
    bool expected2 = false;
    bool expected3 = true;
    bool expected4 = false;
    bool expected5 = true;
    string testfile = "tests/testInputDFS/test";
    testfile+=to_string(3);
    testfile+=".csv";
    DiGraph test(testfile);
    string nodeA = "4", nodeB = "0";
    string nodeC = "3", nodeD = "2";
    bool result1 = test.isReachableIDDFS(nodeA, nodeB, 6);
    bool result2 = test.isReachableIDDFS(nodeA, nodeB, 1);
    bool result3 = test.isReachableIDDFS(nodeB, nodeA, 3);
    bool result4 = test.isReachableIDDFS(nodeC, nodeD, 1);
    bool result5 = test.isReachableIDDFS(nodeC, nodeD, 3);
    REQUIRE(result1 == expected1);
    REQUIRE(result2 == expected2);
    REQUIRE(result3 == expected3);
    REQUIRE(result4 == expected4);
    REQUIRE(result5 == expected5);
}

TEST_CASE("IDDFS, Directed Graph, TXT", "[valgrind][weight=1][part=IDDFS]") {
    
    bool expected1 = false;
    bool expected2 = true;
    bool expected3 = false;
    bool expected4 = true;
    bool expected5 = false;
    string testfile = "tests/testTXT/test";
    testfile+=to_string(6);
    testfile+=".txt";
    DiGraph test(testfile);
    string nodeA = "4", nodeB = "3";
    string nodeC = "3", nodeD = "4";
    string nodeE = "2", nodeF = "3";
    string nodeG = "3", nodeH = "0";
    bool result1 = test.isReachableIDDFS(nodeA, nodeB, 1);
    bool result2 = test.isReachableIDDFS(nodeA, nodeB, 2);
    bool result3 = test.isReachableIDDFS(nodeC, nodeD, 6);
    bool result4 = test.isReachableIDDFS(nodeE, nodeF, 5);
    bool result5 = test.isReachableIDDFS(nodeG, nodeH, 10);
    REQUIRE(result1 == expected1);
    REQUIRE(result2 == expected2);
    REQUIRE(result3 == expected3);
    REQUIRE(result4 == expected4);
    REQUIRE(result5 == expected5);
}





// #define CATCH_CONFIG_MAIN

#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../graphs/digraph.h"
#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

TEST_CASE("test load and make undirected graph", "[valgrind][weight=1]") {
    map<string, set<string>> expected = {{"0", set<string>{"1","2","6"}}, {"1",set<string>{"0","5","3"}}, 
    {"2", set<string>{"0","4"}},{"3", set<string>{"1"}}, {"4", set<string>{"2"}},{"5", set<string>{"1"}},
    {"6", set<string>{"0","7"}},{"7", set<string>{"6"}}};
    string filename = "tests/testInputBFS/test4.csv";
    UdGraph g(filename,1.0);
    vector<string> Nodes = g.getNodes();
    for(vector<string>::iterator it= Nodes.begin();it != Nodes.end();it++){
        REQUIRE(g.getSet(*it) == expected[*it] );
    }
}

TEST_CASE("test load and make directed graph", "[valgrind][weight=1]") {
    map<string, set<string>> expected = {{"0", set<string>{"1","2","6"}}, {"1",set<string>{"5","3"}}, 
    {"2", set<string>{"4"}},{"6", set<string>{"7"}}};
    string filename = "tests/testInputBFS/test4.csv";
    DiGraph g(filename,1.0);
    vector<string> Nodes = g.getNodes();
    for(vector<string>::iterator it= Nodes.begin();it != Nodes.end();it++){
        REQUIRE(g.getSet(*it) == expected[*it] );
    }
}
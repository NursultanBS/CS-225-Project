#include "../cs225/catch/catch.hpp"
#include "../graphs/udgraph.h"
#include "../graphs/digraph.h"
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#include <algorithm>

using namespace std;

void sortVectorOfVector(vector<vector<string>>& res) {
    for (vector<string>& v : res) {
        std::sort(v.begin(), v.end(), [](const string& v1, const string& v2) {return (v1[0] < v2[0]);});
    }
    std::sort(res.begin(), res.end(), [](const vector<string>& v1, const vector<string>& v2) { return (v1[0][0] < v2[0][0]);});
}

TEST_CASE("Strongest connected components", "[valgrind][weight=1]") {
    vector<vector<vector<string>>> expected = { {{"0"}, {"1"}, {"2"}, {"3"}, {"4"}, {"5"}},
                                                {{"0","1","2"}, {"4"}, {"5"}, {"3"}}, 
                                                {{"3","2","1"}, {"4","5"}, {"6"}}, 
                                                {{"1"},{"2","3","4"},{"5"},{"6"}} };
    string testpath = "tests/testTXT/test";
    string ext = ".txt";
    unsigned start_test = 5;
    for (unsigned i=start_test; i<=8; ++i) {
        DiGraph graph (testpath + to_string(i) + ext);
        vector<vector<string>> res = graph.stronglyConnectedComponents();
        sortVectorOfVector(expected[i-start_test]);
        sortVectorOfVector(res);
        REQUIRE(expected[i-start_test] == res);
    }

}



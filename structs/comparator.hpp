#pragma once
#include <utility>
#include "nodestep.hpp"
using std::pair;

// Comparator for pq used in Dijkstra
struct myComparator {
    int operator() (const pair<NodeStep, int> p1, const pair<NodeStep, int> p2) {
        return p1.second > p2.second;
    }
};
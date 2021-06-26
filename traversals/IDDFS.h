#pragma once

#include "traversal.h"
#include "../graphs/graph.h"

#include <iterator>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class IDDFS: public Traversal {
    public:
        IDDFS(Graph* graph, const NodeStep& start, int depth);
        Traversal::Iterator begin();
        Traversal::Iterator end();
        
        void add(const NodeStep & t);
        NodeStep pop();
        NodeStep peek() const;
        bool empty() const; 
        set<string>& getSet(const string& node) const;
        bool contains(const string& node) const;

    private:
        int depth_;
        Graph* graph_;
        NodeStep start_;
        stack<NodeStep> s_;
};
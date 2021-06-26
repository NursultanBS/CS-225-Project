#pragma once
#include "traversal.h"
#include "../graphs/graph.h"

#include <iterator>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class DFS: public Traversal {
    public:
        DFS(Graph* graph, const NodeStep& start);
        Traversal::Iterator begin();
        Traversal::Iterator end();
        
        void add(const NodeStep & t);
        NodeStep pop();
        NodeStep peek() const;
        bool empty() const; 
        set<string>& getSet(const string& node) const;
        bool contains(const string& node) const;
        
    private:
        Graph* graph_;
        NodeStep start_;
        stack<NodeStep> s_;
        
};


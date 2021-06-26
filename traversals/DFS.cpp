#include <iterator>
#include <set>
#include <vector>
#include "DFS.h"
#include "../structs/nodestep.hpp"

using namespace std;

DFS::DFS(Graph* graph, const NodeStep& start) {
    graph_ = graph;
    start_ = NodeStep(start.node, start.step);
}

Traversal::Iterator DFS::begin() {
    return Traversal::Iterator(this, start_);
}

Traversal::Iterator DFS::end() {
    return Traversal::Iterator();
}

void DFS::add(const NodeStep & ns) {
    s_.push(ns);
}

NodeStep DFS::pop() {
    NodeStep ns = peek();
    s_.pop();
    return ns;
}

NodeStep DFS::peek() const {
    return s_.top();
}

bool DFS::empty() const {
    return s_.empty();
}

set<string>& DFS::getSet(const string& node) const {
    return graph_->getSet(node);
}

bool DFS::contains(const string& node) const {
    return graph_->contains(node);
}
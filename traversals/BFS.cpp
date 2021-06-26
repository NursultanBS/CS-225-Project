#include <iterator>
#include <set>
#include <vector>
#include "BFS.h"
#include "../structs/nodestep.hpp"

using namespace std;

BFS::BFS(Graph* graph, const NodeStep& start) {
    graph_ = graph;
    start_ = NodeStep(start.node, start.step);
}

Traversal::Iterator BFS::begin() {
    return Traversal::Iterator(this, start_);
}

Traversal::Iterator BFS::end() {
    return Traversal::Iterator();
}

void BFS::add(const NodeStep & ns) {
    q_.push(ns);
}

NodeStep BFS::pop() {
    NodeStep ns = peek();
    q_.pop();
    return ns;
}

NodeStep BFS::peek() const {
    return q_.front();
}

bool BFS::empty() const {
    return q_.empty();
}

set<string>& BFS::getSet(const string& node) const {
    return graph_->getSet(node);
}

bool BFS::contains(const string& node) const {
    return graph_->contains(node);
}
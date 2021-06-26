#include <iterator>
#include <set>
#include <vector>
#include "IDDFS.h"
#include "../structs/nodestep.hpp"


IDDFS::IDDFS(Graph* graph, const NodeStep& start, int depth) {
    graph_ = graph;
    start_ = NodeStep(start.node, start.step);
    depth_ = depth;
}

Traversal::Iterator IDDFS::begin() {
    return Traversal::Iterator(this, start_);
}

Traversal::Iterator IDDFS::end() {
  return Traversal::Iterator();
}

void IDDFS::add(const NodeStep & ns) {
  if (ns.step <= depth_) {
      s_.push(ns);
  }
}

NodeStep IDDFS::pop() {
  NodeStep top = s_.top();
  s_.pop();
  return top;
}

NodeStep IDDFS::peek() const {
  return s_.top();
}

bool IDDFS::empty() const {
  return s_.empty();
}

set<string>& IDDFS::getSet(const string& node) const {
    return graph_->getSet(node);
}

bool IDDFS::contains(const string& node) const {
    return graph_->contains(node);
}


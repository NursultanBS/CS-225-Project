#include<stack>
#include<queue>
#include<string>
#include<map>
#include<iostream>

#include "../structs/nodestep.hpp"
#include "../graphs/graph.h"
#include "traversal.h"

using namespace std;

Traversal::Iterator::Iterator() {
    traversal_ = NULL;
}

Traversal::Iterator::Iterator(Traversal* traversal, NodeStep& start) {
    traversal_ = traversal;
    if (canMove(start)) traversal_->add(start);
    else traversal_ = NULL;
    visited_.insert(start.node);
    *this = ++*this;
}

Traversal::Iterator& Traversal::Iterator::operator++() {
    if (traversal_ && !traversal_->empty()) {
        current_ = traversal_->pop();
        for (string next : traversal_->getSet(current_.node)) {
            NodeStep nextns(next, current_);    // copy ctor add 1 to the step count
            if (canMove(nextns)) {
                traversal_->add(nextns);
                visited_.insert(current_.node);
            }
        }
    } else {
        traversal_ = NULL;
    }
    return *this;
}

NodeStep Traversal::Iterator::operator*() {
    return current_;
}

bool Traversal::Iterator::operator!=(const Iterator &other) {
    if (!traversal_ && !other.traversal_) return false;
    if (traversal_ && other.traversal_ && current_ == other.current_) return false;
    return true;
}

// limit default is -1, no limit is set.
bool Traversal::Iterator::canMove(const NodeStep& ns, int limit) const {
    if (!traversal_->contains(ns.node)) return false;
    if (limit >=0 && ns.step >= limit) return false;
    if (visited_.find(ns.node) != visited_.end()) return false;
    return true;
}
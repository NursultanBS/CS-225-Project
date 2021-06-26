#pragma once

#include<string>
#include<ostream>
#include <sstream>
#include <iostream>
using std::string;

struct NodeStep {
    string node;
    int step = 0;
    NodeStep(){}
    NodeStep(string nodep, int stepp):node(nodep), step(stepp){}
    NodeStep(string nodep, const NodeStep& other) { // increment step for shortest distance
        node = nodep;   
        step = other.step+1;
    }

    // void operator=(const NodeStep& other) {
    //     if (this != &other) {
    //         node = other.node;
    //         step = other.step;
    //     }
    // }

    bool operator==(const NodeStep& other) {
        return node==other.node && step == other.step;
    }

    bool operator!=(const NodeStep& other) {
        return !(*this == other);
    }

    bool operator==(const string& nodeString) {
        return nodeString==node;
    }
    
    bool operator!=(const string& nodeString) {
        return nodeString!=node;
    }
};

inline std::ostream & operator<<(std::ostream & out, NodeStep const & ns) {
    out << "Graph Node: "<<ns.node<< " at step: "<<ns.step;
    return out;
}
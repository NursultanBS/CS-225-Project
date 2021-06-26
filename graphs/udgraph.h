#pragma once

#include<string>

using namespace std;

#include "graph.h"

class UdGraph: public Graph {
    public:
        UdGraph(const string filename, double loadfactor = 1.0);
        Type type() const;
    private:
        const Type type_ = undirected;
};
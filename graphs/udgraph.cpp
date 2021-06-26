#include "udgraph.h"
#include "graph.h"
#include "../fileloaders/fileloader.h"

#include<string>
#include <iostream>

using namespace std;

UdGraph::UdGraph(const string filename, double loadfactor) {
    try{
        FileLoader(this, filename, loadfactor);
        setFileName(filename);
        setLoadFactor(loadfactor);
    } catch (runtime_error e) {
        cout<<e.what()<<endl;
    }
}

Type UdGraph::type() const {
    return type_;
}

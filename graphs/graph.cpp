#include<string>
#include <fstream>
#include <istream>
#include <iostream>

#include "graph.h"
#include "../structs/nodestep.hpp"
#include "../traversals/BFS.h"
#include "../traversals/DFS.h"
#include "../traversals/IDDFS.h"
#include "../traversals/Dijkstra.h"

using namespace std;


set<string>& Graph::getSet(const string& key){
    return graph_[key];
}

vector<string>& Graph::getNodes(){
    return listOfNodes_;
};

bool Graph::contains(const string& node) {
    if (graph_.find(node) == graph_.end()) return false;
    return true;
}

unsigned Graph::size() const {
    return listOfNodes_.size();
}

string Graph::getRandom() {
    unsigned random_idx = rand() % (listOfNodes_.size());
    return listOfNodes_[random_idx];
}

// -------------------helpers----------------------
void Graph::addNode(const string& lhs, const string& rhs){
    if (!contains(lhs)) {
            graph_[lhs] = set<string>{rhs};
    } else {
        graph_[lhs].insert(rhs);
    }
}

void Graph::addToList(const string& node) {
    if (!contains(node)) {
        graph_[node] = set<string>();
        listOfNodes_.push_back(node);
    }
}

void Graph::setLoadFactor(double lf) {
    loadfactor_ = lf;
}

double Graph::getLoadFactor() const {
    return loadfactor_;
}

void Graph::setFileName(string fn) {
    filename_ = fn;
}

string Graph::getFileName() const {
    return filename_;
}
// ---------------end helpers----------------------

int Graph::getShortestDistance(const string& node, const string& target) {
    if (!contains(node) || !contains(target)) return -1;
    BFS bfs(this, NodeStep(node, 0));
    for (NodeStep it : bfs) {
        if (it == target) return it.step;
    }
    
    return -1;
}

bool Graph::isConnected(const string& node, const string& target) {
    if (!contains(node) || !contains(target)) return -1;
    DFS dfs(this, NodeStep(node, 0));
    for (NodeStep it : dfs) {
        if (it == target) return 1;
    }
    return 0;
}

vector<string> Graph::getLeastWeightedPath(const string& node, const string& target) {
    if (!contains(node) || !contains(target)) return vector<string>();
    Dijkstra dijkstra(this, NodeStep(node, 0));
    vector<string> path;

    for (NodeStep ns : dijkstra) {
        if (ns == target) {
            path = dijkstra.getPath(target);
            return path;
        }
    }
    return vector<string>();
}

bool Graph::isReachableIDDFS(const string& node, const string& target, int max_depth) {
    if (!contains(node) || !contains(target)) return false;
    for (int i = 0; i <= max_depth; ++i) {
        IDDFS iddfs(this, NodeStep(node, 0), i);
        for (NodeStep it : iddfs) {
            if (it == target) return true;
        }
    }
    return false;
}

vector<vector<string>> Graph::stronglyConnectedComponents(unsigned n, unsigned c) {
    /* left empty, implemented in directed graph */
    return vector<vector<string>>();
}

//  <----------Iterator wraper methods---------->
void Graph::bfs(const string& beginNode) {         
    BFS bfs(this, NodeStep(beginNode, 0));
    for (auto it = bfs.begin(); it != bfs.end(); ++it) {
        cout<<(*it)<<endl;
    }
}

void Graph::dfs(const string& beginNode) {   
    DFS dfs(this, NodeStep(beginNode, 0));
    for (auto it = dfs.begin(); it != dfs.end(); ++it) {
        cout<<(*it)<<endl;
    }
}

void Graph::iddfs(const string& beginNode, int max_depth) {   
    for (int i = 0; i <= std::min(i, max_depth); i*=2) {
        IDDFS iddfs(this, NodeStep(beginNode, 0), i);
        for (auto it = iddfs.begin(); it != iddfs.end(); ++it) {
            cout<<(*it)<<endl;
        }
    }
}



#include "digraph.h"
#include "graph.h"
#include "../fileloaders/fileloader.h"

#include<string>
#include<queue>
#include <iostream>

using namespace std;

DiGraph::DiGraph() {
}

DiGraph::DiGraph(const string& filename, double loadfactor) {
    try{
        FileLoader(this, filename, loadfactor);
        setFileName(filename);
        setLoadFactor(loadfactor);
    } catch (runtime_error e) {
        cout<<e.what()<<endl;
    }
}


Type DiGraph::type() const {
    return type_;
}

// will be used for SSC algorithm
DiGraph* DiGraph::createTranspose() {
    DiGraph* trans = new DiGraph;
    for (string& node : getNodes()) {
        trans->addToList(node);
        set<string>& old = getSet(node);    // original adj list with outgoing (node) to incoming (every node in old)
        for (const string& newFrom : old) {
            trans->addToList(newFrom);
            trans->addNode(newFrom, node);
        }
    }
    return trans;
}

// Kosaraju's algorithm
vector<vector<string>> DiGraph::stronglyConnectedComponents(unsigned n, unsigned c) {  
    vector<vector<string>> ssc;
    DiGraph* transpose = createTranspose();
    // perform first DFS on transpose
    vector<string> transResult; // This vector store the results from DFS on transpose
    set<string> visited;
    // cout<<"transResult size: "<<transResult.size()<<" at line: "<<__LINE__<<endl;
    for (string node : transpose->getNodes()) {
        DFS_lite(transResult, visited, transpose, node);
    }

    delete transpose;
    if (transResult.size()==0) return ssc;
    visited.clear();    

    auto compare = [](vector<string>& v1, vector<string>& v2) {
        return v1.size() > v2.size();
    };

    // min heap used to keep track of top n candidates
    priority_queue<vector<string>, vector<vector<string>>, decltype(compare)> pq(compare);

    // perform second DFS on graph_
    for (unsigned i=transResult.size()-1; i>=0; i--) {
        vector<string> sub_component;
        DFS_lite(sub_component, visited, this, transResult[i]);

        // If the next sub-component is better than current worst candidate in pq, then pop the first in pq
        if (!pq.empty() && pq.size() == n && pq.top().size() < sub_component.size()) pq.pop();

        // if there is any vacancy, add to pq
        if (sub_component.size() >= c && pq.size() < n) pq.push(sub_component);
        if (i==0) break;
    }

    while (!pq.empty()) {
        ssc.push_back(pq.top());    
        pq.pop();
    }
    
    return ssc;
}

void DFS_lite(vector<string>& res, set<string>& visited, Graph* g, string node) {
    if (visited.find(node) != visited.end()) return;
    visited.insert(node);
    for (string next : g->getSet(node)) {
        DFS_lite(res, visited, g, next);
    }
    res.push_back(node);
}

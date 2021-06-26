#pragma once

#include <fstream>
#include <istream>
#include <iostream>
#include <string>

#include "../fileloaders/fileloader.h"
#include "../graphs/graph.h"
#include "../graphs/digraph.h"
#include "../graphs/udgraph.h"
#include "nodestep.hpp"
#include "../traversals/traversal.h"
#include "../traversals/BFS.h"
#include "../traversals/DFS.h"
#include "../traversals/Dijkstra.h"
#include "../traversals/IDDFS.h"
using namespace std;

struct Util {
    Graph* graph = NULL;

    // init random seed
    Util() {
        srand(time(0));
    }
    ~Util() {
        if (!graph) delete graph;
    }

    bool validNumber(string input) {
        if (input.size() == 0) return false;
        for (char c : input) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    void printActions() {
        cout<<endl;
        cout<<"1: Load/Replace data"<<endl;
        cout<<"2: Run graph search algorithms"<<endl;
        cout<<"8: Help"<<endl;
        cout<<"9: Exit"<<endl;
    }

    void printDataStatus() {
        cout<<endl;
        if (graph==NULL) {
            printf("\033[31mYou do not have data loaded.\033[0m\n");
        }
        else if (graph->type() == undirected) {
            printf("\033[32m %s loaded as undirected graph with loadfactor %f and %d nodes\033[0m\n", graph->getFileName().c_str(), graph->getLoadFactor(), graph->size());
        }
        else if (graph->type() == directed) {
            printf("\033[32m %s loaded as directed graph with loadfactor %f and %d nodes\033[0m\n", graph->getFileName().c_str(), graph->getLoadFactor(), graph->size());
        }
    }

    // Load and create graph base on user specified type
    void loadGraph(string filename, Type t, double loadfactor=1.0) {
        if (graph != NULL) delete graph;
        graph = NULL;
        filename = "assets/"+filename;
        printf("\033[33m building graph...\033[0m\n");
        if (t == undirected) {
            graph = new UdGraph(filename, loadfactor);
        } else if (t == directed) {
            graph = new DiGraph(filename, loadfactor);
        }
        if (graph->size() == 0) {
            delete graph;
            graph = NULL;
            printf("\033[31m failed, graph contains 0 node\033[0m\n");
        }
    } 

    void loadGraphHandler() {
        string filename;
        int type = -1;
        double loadfactor = -1;
        cout<<"Step 1: Please put your data file in assets folder. Input 9 if you do not want to mount data anymore."<<endl;
        while (filename.size() < 4 || (filename.substr(filename.size()-4) != ".txt" && filename.substr(filename.size()-4) != ".csv")) {
            cout<<"Step 2: Type your filename with extension, and do not include filepath: ";
            cin>>filename;
            if (filename == "9") return;
        }
        while (type != 0 && type != 1) {
            cout<<"Step 3: Please input 0 for directed graph, or input 1 for undirected graph: ";
            cin>>type;
            if (type == 9) return;
        }
        while (loadfactor < 0) {
            cout<<"Step 4: Please indicate what portion of data you would like to load (0.0-1.0]: ";
            cin>>loadfactor;
            if (loadfactor > 1) loadfactor = 1.0;
        }
        if (type == 0) loadGraph(filename, directed, loadfactor);
        if (type == 1) loadGraph(filename, undirected, loadfactor);
    }

    void algorithmHandler() {
        vector<string> ops = {"DFS", "BFS", "IDDFS", "Dijkstra", "SCC"};
        if (graph == NULL) {
            cout<<"Please load data first."<<endl;
            return; // No graph, no run
        }
        cout<<endl;
        for (unsigned i=0; i<ops.size(); ++i) {
            if (ops[i] == "SCC" && graph->type() != directed) continue;
            cout<<i<<": "<<ops[i]<<endl;
        }
        cout<<endl;
        string the_op;
        bool fst = 1;
        while (the_op.size() == 0) {
            string op = "-1";
            cout<<"Please select the algorithm you like to perform, input 9 return to main menu: ";
            cin>>op;
            if (!isdigit(op[0])) continue;
            if (op=="9") return;
            int idx = stoi(op);
            if (idx<0 || idx >= (int)ops.size()) continue;
            if (graph->type() != directed && idx == (int) ops.size()-1) {
                cout<<endl;
                cout<<"SCC can only be performed on directed graph!"<<endl;
                continue;
            }
            the_op = ops[idx];
        }
        cout<<"You have selected "<<the_op<< " algorithm"<<endl;
        algorithmDispatcher(the_op);
    }

    string selectNode(int state) {  // state used for source/destination selection
        string str;
        if (state == 0) str = "source";
        else str = "destination";
        string answer;
        while (answer.size() == 0) {
            cout<<"Input "<<str<<" number, "<< "-1 for picking a random one: ";
            cin>>answer;
            if (answer == "-1") {
                answer = graph->getRandom();
            } else if (!graph->contains(answer)) {
                cout<<answer<<" is not a valid data point, please select again!"<<endl;
                answer.clear();
            }
        }
        return answer;
    }

    void algorithmDispatcher(string the_op){
        cout<<endl;
        printf("\033[34m <<<<<<<<<<<<  Running %s  >>>>>>>>>>>>\033[0m\n", the_op.c_str());
        if (the_op == "DFS") {
            performDFS();
        }
        if (the_op == "BFS") {
            performBFS();
        }
        if (the_op == "IDDFS") {
            performIDDFS();
        }
        if (the_op == "Dijkstra") {
            performDijkstra();
        }
        if (the_op == "SCC") {
            performSCC();
        }
    }

    void performDFS() {
        string from = selectNode(0);
        string to = selectNode(1);
        performDFS(from, to);
    }

    void performBFS() {
        string from = selectNode(0);
        string to = selectNode(1);
        performBFS(from, to);
    }

    void performIDDFS() {
        string from = selectNode(0);
        string to = selectNode(1);
        int step = -1;
        while (step < 0 ) {
            string step_input;
            cout<<"Input a positive integer for IDDFS maximum search depth: ";
            cin>>step_input;
            if (validNumber(step_input)) step = stoi(step_input);
        }
        performIDDFS(from, to, step);
    }

    void performDijkstra() {
        string from = selectNode(0);
        string to = selectNode(1);
        cout<<"Find leasted weighted path from "<<from<< " to "<<to<<endl;
        performDijkstra(from, to);
    }

    void performSCC() {
        if (graph->type() != directed) {
            cout<<"SSC can only be performed on directed graph."<<endl;
            return;
        }
        unsigned limiting_number = 0, components_limiting_size = 0;
        while(limiting_number == 0) {
            string in;
            cout<<"Input number of strongly connected components to display: ";
            cin>>in;
            if (validNumber(in)) {
                limiting_number = stoi(in);
            }
        }
        while(components_limiting_size == 0) {
            string in;
            cout<<"Input SCC threshold: ";
            cin>>in;
            if (validNumber(in)) {
                components_limiting_size = stoi(in);
            }
        }
        performSCC(limiting_number, components_limiting_size);
    }

    void performDFS(const string& from, const string& to) {
        cout<<"Find if path exist from "<<from<< " to "<<to<<endl;
        bool res = graph->isConnected(from, to);
        if (res) {
            cout<<"There exist a path from ";
        } else {
            cout<<":(  There is no path from ";
        }
        cout<<from<<" to "<<to<<endl;
    }

    void performBFS(const string& from, const string& to) {
        cout<<"Searching shortest distance from "<<from<< " to "<<to<<endl;
        int output = graph->getShortestDistance(from, to);
        if (output >= 0) {
            cout<<"The shortest distance from "<<from << " to "<< to <<" is "<<output<<"!"<<endl;
        } else {
            cout<<"There is no path from: "<<from << " to "<< to <<endl;
        }
    }

    void performIDDFS(const string& from, const string& to, int step) {
        cout<<"Find if path exist from "<<from<< " to "<<to<<" within "<<step<<" steps."<<endl;
        bool res = graph->isReachableIDDFS(from, to, step);
        if (res) {
            cout<<"There exist a path from ";
        } else {
            cout<<":(  There is no path from ";
        }
        cout<<"Node: "<<from<<" to "<<to<< " within "<<step<<" steps"<<endl;
    }

    void performDijkstra(const string& from, const string& to) {
        vector<string> res = graph->getLeastWeightedPath(from, to);
        if (res.size() == 0) {
            cout<<"There is no path from: "<<from<<" to "<<to<< " :("<<endl;
        } else {
            cout<<"Path identified: ";
            for (unsigned i=0; i<res.size(); i++) {
                cout<<res[i];
                if (i < res.size()-1) {
                    cout<<" -> ";
                }
            }
            cout<<endl;
        }
    }

    void performSCC(int limiting_number, int components_limiting_size) {
        vector<vector<string>> res = graph->stronglyConnectedComponents(limiting_number, components_limiting_size);
        if (res.size() == 0) {
            cout<<"No Strongly Connected Component found based on your parameter!"<<endl;
            return;
        }

        cout<<"<<<Strongly Connected Component in asscending order>>>"<<endl;
        //cout<<res.size()<<endl;

        for (vector<string>& scc : res) {
            cout<<endl;
            printf("\033[34m <---------------  SCC with %lu nodes  --------------->\033[0m\n", scc.size());
            for (unsigned i=0; i<scc.size(); i++) {
                cout<<scc[i];
                if (i == scc.size()-1) break;
                cout<<", ";
            }
            cout<<endl;
        }
    }
};
#pragma once

#include<map>
#include<set>
#include<vector>
#include<string>

using namespace std;

enum Type {
    undirected,
    directed
};

class Graph{
    public:
        Type type_;

        // Return Enum undirected or directed
        virtual Type type() const = 0;

        // Given a key as vertex, return its neghibours in a reference of set 
        virtual set<string>& getSet(const string& key);

        // Lookup if the graph contains a vertex
        virtual bool contains(const string& node);

        // Return a vector of all vertexs in the graph
        virtual vector<string>& getNodes();
/*
        // Helper function used for constructing edges table
        virtual void setWeights();

        // retrive edge weight from two given vertexs
        virtual int getWeight(pair<string,string> edge);*/

        // return a random existing node
        virtual string getRandom();
        
        // helper functions for derived class to constructe graph
        virtual void addNode(const string& lhs, const string& rhs);
        virtual void addToList(const string& node);     // Add to a vector that contains all vertexs.
        virtual unsigned size() const;                  // Number of vertexs
        /***
         * graph search algorithms
         */
        // Search a distance from a node to the target through BFS
        // Return -1 if there is no such connection between node and target
        virtual int getShortestDistance(const string& node, const string& target); 
        virtual bool isConnected(const string& node, const string& target); 

        // Search the shortest distance from a node to the target on a weighted map
        // Use Dijkstra’s algorithm
        // Return -1 if there is no such connection between node and target
        virtual vector<string> getLeastWeightedPath(const string& node, const string& target);

        // If there exist a walk from a node to the target within n walks / maximun depth, return true
        virtual bool isReachableIDDFS(const string& node, const string& target, int max_depth);
        
        //  <----------Iterator wraper methods---------->
        virtual void bfs(const string& beginNode);
        virtual void dfs(const string& beginNode);
        virtual void iddfs(const string& beginNode, int max_depth);
        virtual void setLoadFactor(double lf);
        virtual double getLoadFactor() const;
        virtual void setFileName(string filename);
        virtual string getFileName() const;

        // Only will be overloaded in directed graph
        virtual vector<vector<string>> stronglyConnectedComponents(unsigned n = 1000, unsigned c = 1);

    private:
        // Representing our graph in a hashmap
        map<string, set<string> > graph_;

        // All unique nodes stored in a list for generating random node
        vector<string> listOfNodes_;
        double loadfactor_ = 1.0;
        string filename_;
};


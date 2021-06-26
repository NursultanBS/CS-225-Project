#include "structs/util.hpp"

int main (int argc, char** argv) {
    

    Util util;

    // one-line cmd run
    if (argc >= 7) {
        string filename;
        string loadfactor_s = argv[3];
        double loadfactor;
        filename = argv[1];
        loadfactor = stof(loadfactor_s);
        string(argv[2]) == "directed" ? util.loadGraph(filename, directed, loadfactor) : util.loadGraph(filename, undirected, loadfactor);
        string algorithm = argv[4];
        string from = argv[5];
        string to = argv[6];

        if (from == "-1") from = util.graph->getRandom();
        if (to == "-1") to = util.graph->getRandom();
        
        util.printDataStatus();

        if (algorithm == "DFS") util.performDFS(from, to);
        else if (algorithm == "BFS") util.performBFS(from, to);
        else if (algorithm == "IDDFS" && argc>= 8) util.performIDDFS(from, to, stoi(string(argv[7])));
        else if (algorithm == "Dijkstra") util.performDijkstra(from, to);
        else if (algorithm == "SCC") util.performSCC(stoi(string(argv[5])), stoi(string(argv[6])));
        else cout<<"Please check your input format."<<endl;
        return 0;
    }

    // console user interaction
    cout<<" ------------------------------- "<<endl;
    cout<<"| General Graph Search Tool 1.0 |"<<endl;
    cout<<" ------------------------------- "<<endl;

    while (true) {
        string input;
        util.printDataStatus();
        cout<<"Please input number 1-9 for your action (8 for help): ";
        cin>>input;
        
        if (input == "1") util.loadGraphHandler();
        if (input == "2") util.algorithmHandler();
        if (input == "8") util.printActions();
        if (input == "9") break;
    }

    cout<<"Goodbye!"<<endl;
    return 0;
}
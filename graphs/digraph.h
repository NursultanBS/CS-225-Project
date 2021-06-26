#include<string>
#include<vector>

using namespace std;

#include "graph.h"

class DiGraph: public Graph {
    public:
        DiGraph();
        DiGraph(const string& filename, double loadfactor = 1.0);
        Type type() const;
        // set a limit, show max n=1000 components, and each component must be has size larger than 1
        vector<vector<string>> stronglyConnectedComponents(unsigned n = 1000, unsigned c = 1);

    private:
        const Type type_ = directed;
        DiGraph* createTranspose(); // generate transpose of current DiGraph
};

void DFS_lite(vector<string>& res, set<string>& visited, Graph* g, string node);
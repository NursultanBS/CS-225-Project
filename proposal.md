# Proposal

1. **Leading Question:**<br>
The proposed project aims to produce a general search tool for both directed and undirected graph data structure. This search tool will be able to read in the data in csv and txt format, generate a directed or undirected graph, find the shortest path and search a target in the graph. 
To find the shortest path of two nodes in any input data set we can perform a Breadth-First Search (BFS). To query whether there exists a path between two given nodes, we can perform a Depth First Search (DFS). When we want to handle more complicated situations, for example, finding the shortest path in a weighted graph, we want to perform Dijkstra Search, and when we want to find the existence of a path between nodes in unknown data size, we can perform Iterative Deepening Depth-First Search (IDDFS).  

2. **Dataset Acquisition and Processing:**<br>
To demonstrate our tool is general, we decided to use Github social network, Gnutella peer-to-peer network and California road network datasets.
We decided to include the downloaded raw data files in our directory and use fileloader class to read our data line by line. We will implement a feature in fileloader class to recognize csv and txt extension, and parse data accordingly. More specifically, for csv data, we will read one node on the left side of the comma, and the other node on the other side. For txt file, space separates two nodes. Users will need to specify whether the loaded data is a directed graph or undirected graph. 
To represent a graph in an adjacency list, we are going to use a map to store the node’s number as a key, and for value, we will have a list of nodes that the key node can expand. To store nodes and neighbours in map<node, set<node>> allows retrieving and querying node information in constant time. 
We recognize that all the datasets are large and could have errors or missing entries, thus, we will implement sanity check functions such as checking valid file extensions and valid nodes when parsing raw data.

3. **Graph Algorithms:** <br>
We will use BFS to find the shortest distance. The inputs will be a start node and a target node. We expand from the start node and return the number of nodes traversed if we find a target, else if target is not found -1 is returned. The time complexity of BFS traversal is O(V+E), where V is the number of vertices and E is the number of edges.<br>
We also plan to implement DFS as a general search algorithm. The inputs will be a start node and a target node. We expand from the start node and traverse until a target node is found or all the nodes are visited. Return a boolean to indicate if the target node is found or not. The time complexity of DFS traversal is also O(V+E).<br>
We define weights of edges by counting the number of node’s neighbours, and we use Dijkstra's algorithm to find the shortest path. The inputs are a start node and a target node. Depending on how we define the priority, we yield a path with the largest or smallest weight. The expected time complexity of Dijkstra’s algorithm is O(E*logV).<br>
We propose to use IDDFS to optimize search. Inputs: a start node, a target node, a number describing max depth this search can go. Return a boolean to indicate if the target is reachable. Let b be the branching factor. Let d denotes the minimal depth needed for finding the target node. The time complexity of IDDFS algorithm is O(b^(d)).<br>
 
4. **Timeline:**<br>
Week of April 12 - April 18, create the directory structure and empty files. Implement the fileloader class to load data. Build graph classes and adjacency list.<br>
Week of April 19 - April 25, base traversal class, iterator, BFS algorithm, and test cases.<br>
Week of April 26 - May 2, DFS, Dijkstra, IDDFS, and test cases.<br>
Week of May 3 - May 9, finish DFS, Dijkstra, IDDFS, and implement user interaction.<br>
Week of May 10 - May 12 has three days to make a demo video.

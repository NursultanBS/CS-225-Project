# nb17-xzeng17-xiaojun7-yuesong3

***Presentation Video***

https://youtu.be/lkfoLybeqss

***Obtained data source from:***

1. GitHub Social Network   http://snap.stanford.edu/data/github-social.html
2. California Road Network http://snap.stanford.edu/data/roadNet-CA.html
3. Gnutella peer to peer network from August 8 2002 http://snap.stanford.edu/data/p2p-Gnutella08.html

***File Directory:***

project <br>
|   <br>
|__assets:       contains data   <br>
|__cs225:        makefile and catch  <br>
|__fileloaders:  class used to read data and create graph    <br>
|__graphs:       graph classes   <br>
|__structs:      utility structs, (traversal algorithms and UI)  <br>
|__tests:        test suites <br>
|__traversals:   contains all our algorithms implementation  <br>
|   <br>
main.cpp        <br>

***Compile Program:***

1. To compile file: $ make
2. To compile test case: $ make test
3. To run the main.cpp: $ ./main
4. To run all test case: $ ./test

***User Guide:***

**Start and Load Graph**
1. start the program with $ ./main
2. You entered the main menu from step 1. Navigation system will be very similar to a mobile service robot.
3. Input 1 for loading/replacing data. This allows you to load a graph from assets folder. <br>
You only need to type the file name with extension. <br>
You have to select whether the graph is a directed graph or undirected graph. The data set we selected have simple representation, and you can build them into either directed or undirected graph. <br>
The third option is to decide how much data you want to load. For example, The roadNet-CA.txt is very very large, and I recommend only load 0.005! <br>
After that, when you are back to the main menu, you will see that your data has been loaded with additional informations. <br>
4. After you have loaded the data, you can input 2 for running some algorithms. <br>

***Run Algorithms***<br>

When you entered "Run graph search algorithms", you will again see a list of available actions. <br>
0: DFS<br>
1: BFS<br>
2: IDDFS<br>
3: Dijkstra<br>
4: SCC (only available when directed graph is loaded)<br>

**Help**

Input 8 to reveal the actions you can do.

**Exit**

Input 9 to exit program.

**Command oneline**

If you decide to not to use our user-interaction console, you can run algothem on graph in the following format.
$ ./main [data filename] [graph type] [graph load factor] [Algorithm] [parameter 1] [parameter 2] [parameter 3]
<li> DFS parameter 1: source vertex (string number), parameter 2: destination vertex (string number)
<li> BFS parameter 1: source vertex (string number), parameter 2: destination vertex (string number)
<li> IDDFS parameter 1: source vertex (string number), parameter 2: destination vertex (string number), parameter 3: maximum depth (positive int)
<li> Dijkstra parameter 1: source vertex (string number), parameter 2: destination vertex (string number)
<li> SCC parameter 1: number of SSC to display, parameter 2: Threshold number for SSC
<li> Plug in -1 for string number to get a random node

Examples:<br>
$ ./main musae_git_edges.csv undirected 1.0 DFS -1 -1   <br>
$ ./main musae_git_edges.csv undirected 1.0 BFS -1 -1   <br>
$ ./main musae_git_edges.csv undirected 1.0 IDDFS -1 -1 100 <br>
$ ./main musae_git_edges.csv undirected 1.0 Dijkstra -1 -1  <br>
$ ./main roadNet-CA.txt directed 0.005 SCC 3 5   <br>
$ ./main p2p-Gnutella08.txt directed 1 SCC 3 1   <br>

Tips:
1. roadNet-CA.txt is 80 mb and it is almost impossible to load the entire graph, therefore we suggest only load 0.005 portion. We tested at 0.01, it worked locally but not on ews.
2. Original data musae_git_edges.csv and roadNet-CA.txt are undirected graph, and p2p-Gnutella08.txt is directed grpah. However, you can still load datas as either directed/undirected graph.
3. For test purpose, we recommend load data as undirected graph to test DFS, BFS, IDDFS and Dijkstra if you want to select random node otherwise expect to see many no path exist result.

**Test suites:**

We adapted the cs225's test suites and wrote personalized data sets to specifically test the edge cases that we might encounter in real data.
The tests mainly focus on the accuracy of our algorithms.
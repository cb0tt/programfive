#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"
#include <vector>
using namespace std;
int main()
{
    WeightedGraph myGraph(10);
    Vertex* startNode;
    Vertex* aVertex;
    startNode = new Vertex("A");
    myGraph.addVertex(startNode);
    aVertex = new Vertex("B");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("C");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("D");
    myGraph.addVertex(aVertex);
    aVertex = new Vertex("E");
    startNode = aVertex;
    myGraph.addVertex(aVertex);
    myGraph.addEdge(0,3,60);
    myGraph.addEdge(0,2,12);
    myGraph.addEdge(1,0,10);
    myGraph.addEdge(2,1,20);
    myGraph.addEdge(2,3,32);
    myGraph.addEdge(4,0,7);

    cout << "DFS: ";
    myGraph.DFS(startNode);
    cout << endl;

    cout << "BFS: ";
    myGraph.BFS(startNode);
    cout << endl;
    vector<Vertex*> path;
    int pathLength;
    myGraph.findPath(startNode, aVertex, path, pathLength);
    return 0;
}

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <vector>
#include "Vertex.h"
#include <string>

using namespace std;
class WeightedGraph
{
public:
    WeightedGraph(int);
    bool isEmpty();
    void addVertex(Vertex*);
    void addEdge(int, int, int);
    bool isFull();
    void DFS(Vertex*);
    void BFS(Vertex*);
    bool doFindPath(Vertex*, Vertex*, vector<Vertex*> &, int&);
    bool findPath(Vertex*, Vertex*, vector<Vertex*> &, int&);
    Vertex* getNodeLetter(const string& title);


protected:
    int indexIs(Vertex*);
    void clearMarks();
    void doDFS(Vertex*, int);
    void doBFS(Vertex*);
private:
    static const int NULL_EDGE = 0;
    int m_numVertices;
    int m_maxVertices;
    vector <Vertex*> m_vertices;
    vector <vector <int>> m_edges;
    vector <bool> m_marks;

};
#endif // WEIGHTEDGRAPH_H


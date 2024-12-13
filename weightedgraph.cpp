#include "weightedgraph.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>

WeightedGraph::WeightedGraph(int size)
{
    m_numVertices = 0;
    m_maxVertices = size;
    m_vertices.resize(size);
    for (int i=0; i<size; i++){
        m_vertices[i] = NULL;
    }

    m_marks.resize(size);

    int rows = size;
    int columns = size;
    m_edges.resize(rows, vector<int>(columns, 0));


}

bool WeightedGraph::findPath(Vertex* source, Vertex* destination, vector<Vertex*> &path, int& pathLength) {
    string nodeOne, nodeTwo;

    cout << "Enter the starting node: ";
    cin >> nodeOne;
    cout << "Enter the destination node: ";
    cin >> nodeTwo;

    Vertex* start = getNodeLetter(nodeOne);
    Vertex* end = getNodeLetter(nodeTwo);

    if (!start) {
        cout << "Starting node does not exist: " << nodeOne << endl;
        return false;
    }
    if (!end) {
        cout << "Destination node does not exist: " << nodeTwo << endl;
        return false;
    }


    clearMarks();
    path.clear();
    pathLength = 0;


    if (doFindPath(start, end, path, pathLength)) {

        cout << "Path: ";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i]->getTitle() << " ";
        }
        cout << endl;

        cout << "Path length: " << pathLength << endl;
        return true;
    } else {
        cout << "No path exists." << endl;
        return false;
    }
}


Vertex* WeightedGraph::getNodeLetter(const string& title) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] != nullptr && m_vertices[i]->getTitle() == title) {
            return m_vertices[i];
        }
    }
    return nullptr;
}




bool WeightedGraph::doFindPath(Vertex* current, Vertex* destination, vector<Vertex*> &path, int& pathLength) {

    if (current == destination) {
        path.push_back(current);
        return true;
    }

    int ix = indexIs(current);
    m_marks[ix] = true;
    path.push_back(current);

    for (int i = 0; i < m_numVertices; i++) {
        if (m_edges[ix][i] != NULL_EDGE && !m_marks[i]) {
            int weight = m_edges[ix][i];

            if (doFindPath(m_vertices[i], destination, path, pathLength)) {
                pathLength += weight;
                return true;
            }

        }
    }

    path.pop_back();
    return false;
}










void WeightedGraph::addVertex(Vertex* aVertex)
{
    m_vertices[m_numVertices] = aVertex;
    for (int i=0; i<m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight)
{
    int row;
    int column;
    row = indexIs(m_vertices[fromVertex]);
    column = indexIs(m_vertices[toVertex]);
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex)
{
     int i = 0;
     while (i < m_numVertices) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
        i++;
     }
     return -1;
}

void WeightedGraph::clearMarks()
{
    for (int i=0; i<m_numVertices; i++) {
        m_marks[i] = false;
    }
}

void WeightedGraph::doDFS (Vertex* aVertex, int cost)
{
    int ix, ix2;
    if (aVertex == NULL)
    {
        cout << cost << endl;
        return;
    }


    cout << aVertex->getTitle() <<" " << cost << endl;
    ix = indexIs(aVertex);
    m_marks[ix] = true;

    for (int i=0; i<m_numVertices; i++) {
        ix2 = indexIs(m_vertices[i]);
        if(m_edges[ix][ix2] != NULL_EDGE) {
            if (m_marks[i] == false){
                int weight = m_edges[ix][ix2];
                doDFS(m_vertices[i], cost + weight);
            }

        }

    }


}

void WeightedGraph::DFS(Vertex* aVertex)
{
    clearMarks();
    doDFS(aVertex, 0);
}
void WeightedGraph::doBFS(Vertex* aVertex)
{

  int ix, ix2;
  queue<Vertex*> que;
  ix = indexIs(aVertex);
  vector<int> cost(m_numVertices, -1);
    cost[ix] = 0;

    m_marks[ix] = true;
    que.push(aVertex);

    while (!que.empty()) {
        Vertex* node = que.front();
        que.pop();
        ix = indexIs(node);


        for (int i = 0; i < m_numVertices; i++) {
            ix2 = indexIs(m_vertices[i]);
            if (m_edges[ix][ix2] != NULL_EDGE) {
                if (m_marks[ix2] == false) {
                    m_marks[ix2] = true;
                    que.push(m_vertices[i]);


                    if (cost[ix2] == -1) {
                        cost[ix2] = cost[ix] + m_edges[ix][ix2];

                    }
                }
            }
        }
        cout << node->getTitle() << " " << cost[ix] << endl;


    }
}

void WeightedGraph::BFS(Vertex* aVertex)
{
    clearMarks();
    doBFS(aVertex);
}

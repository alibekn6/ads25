#include <iostream>
#include <vector>
#include <list>
using namespace std;


class graph {
private:
    int numVertices;
    vector<list<int>> adjList;
    bool isDirected;

public:
    graph(int vertices, bool directed = false) {
        numVertices = vertices;
        isDirected = directed;
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    

}

int main () {


    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];
bool visited[MAXN];
int n;


void BFS(int source) {
    queue<int> q;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[source] = true;
    q.push(source);

    cout << "BFS traversal: ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        

        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];

            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }

    }

    cout << endl;

}

void BFS_with_distance (int source) {
    queue<int> q;
    int distance[MAXN];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = -1;
    }

    visited[source] = true;
    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = true;
                distance[u] = distance[v] + 1;
                q.push(u);
            }
        }
    }


    cout << "Distances from vertex " << source << ":" << endl;

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": ";
        if (distance[i] == -1) {
            cout << "unreachable" << endl;
        } else {
            cout << distance[i] << endl;
        }
    }

}


void BFS_with_path(int source, int target) {
    queue<int> q;
    int parent[MAXN];
    
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    visited[source] = true;


}


int main () {


    n = 6;

    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[1].push_back(4);


    adj[2].push_back(0);
    adj[2].push_back(5);

    adj[3].push_back(4);
    adj[4].push_back(1);
    adj[5].push_back(2);

    BFS_with_distance(0);

    return 0;

}


/*



1. Create a queue Q
2. Mark source vertex as visited
3. Enqueue source vertex
4. While Q is not empty:
   a. Dequeue vertex v from Q
   b. Process vertex v
   c. For each neighbor u of v:
      - If u is not visited:
        * Mark u as visited
        * Enqueue u



        0
       / \
      1   2
     / \   \
    3   4   5



*/
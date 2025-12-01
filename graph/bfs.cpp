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


}


int main () {




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
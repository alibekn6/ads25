#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void ano() {

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }


    int start, end;
    
    cin >> start >> end;
    
    start--;
    end--;

    vector<int> dist(n, -1);

    queue<int> q;
    
    dist[start] = 0;

    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && dist[i] == -1) {
                dist[i] = dist[v] + 1;
                q.push(i);
            }
        }
    }


    cout << dist[end];




}

int main () {

    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }


    int start, end;

    cin >> start >> end;

    start--;
    end--;

    queue<pair<int, int>> q;
    vector<bool> visited(n, false);

    q.push( {start, 0} );
    visited[start] = true;

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == end) {
            cout << dist;
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (adj[cur][i] == 1 && !visited[i]) {
                q.push( { i, dist+1 } );
                visited[i] = true;
            }
        }
    }

    cout << -1;
    
    return 0;

}
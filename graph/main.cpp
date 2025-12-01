#include <vector>
#include <iostream>
#include <cstring>
using namespace std;


const int MAXN = 1000;
// adjacency matrix Fast edge lookup - O(1) 
class GraphMatrix {

    // vector<vector<int> > adj;

    int adj[MAXN][MAXN];

    int n;

public:

    // GraphMatrix (int n) {
    //     adj = vector<vector<int>> (n, vector<int>(n, 0) );
    // }

    GraphMatrix(int n) {
        this-> n = n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
    }


    void add_edge(int u, int v) {

        if (u >= n || v >= n) {
            cout << "Error: Vertex out of bounds " << endl;
            return;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;   
    }

    void add_directed_edge(int u, int v) {
        adj[u][v] = 1;
    }

    void add_weighted_edge(int u, int v, int w) {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    bool has_edge(int u, int v) {
        return adj[u][v] != 0;
    }


    void print() {
        cout << "Printing the graph" << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    

    void print2() {
        cout << "Adjacency Matrix:" << endl;

        cout << "   ";
        

        for (int i = 0; i < n; i++) {
            cout << i << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++) {
            cout << i << " [";

            for (int j = 0; j < n; j++) {
                cout << adj[i][j];
                if (j < n - 1) cout << " ";
            }

            cout << "]" << endl;
        }
    }

};


// adjacency list
class GraphList {
    vector<int> adj[MAXN];
    int n;
public:


    GraphList(int n) {
        this-> n = n;

        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // 1 - 5 - 9

    // 1 | 9

    // 5 == 9
    bool has_edge(int u, int v) {
        for (int i = 0; i < adj[u].size(); i++) {
            if (adj[u][i] == v) {
                return true;
            } 
        }
        return false;
    }

    void print_list() {
        cout << "Adjacency list " << endl;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j];
                if (j < adj[i].size() - 1) {
                    cout << ", ";
                }
            }

            cout << endl;

        }
    }
};



// adjacency list

/*

    
        1  -  5
      /  \ 
    2      3 


    1 -> 2 -> 3 -> 5 -> null;
    
*/





int main () {

    int n = 4;

    GraphMatrix g(n);


    g.add_edge(0, 0);
    g.add_edge(1, 1);
    g.add_edge(2, 2);
    g.add_edge(3, 3);


    GraphList gg(n);

    gg.add_edge(0, 1);
    gg.add_edge(0, 3);
    gg.add_edge(1, 2);
    gg.add_edge(2, 3);
    


    
    // 0 - > 1


    gg.print_list();

    cout << gg.has_edge(0, 1) << endl;
    return 0;
}
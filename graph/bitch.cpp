#include <vector>
#include <iostream>
using namespace std;


const int MAXN = 1000;
vector<int> adj[MAXN];

vector<pair<int, int>> adjw[MAXN];

int n;


void add_weighted_edge(int u, int v, int weight) {
    adjw[u].push_back({ v, weight });
    adjw[v].push_back({ u, weight });
}

void add_directed_weighted_edge(int u, int v, int weight) {
    adjw[v].push_back({ u, weight });
}

void print_weighted_list() {
    for (int i = 0; i < n; i++) {
        cout << i << " [ ";

        for (int j = 0; j < adjw[i].size(); j++) {
            cout << "(" << adjw[i][j].first << "," << adjw[i][j].second << ")";
            if (j < adjw[i].size() - 1) {
                cout << ", ";
            }
        }

        cout << " ]" << endl;
    }
}




void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void add_directed_edge(int u, int v) {
    adj[u].push_back(v);
}

bool has_edge(int u, int v) {
    for (int i = 0; i < adj[u].size(); i++) {
        if (adj[u][i] == v) {
            return true;
        }
    }
    return false;
}


void print_list() {
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < adj[i].size(); j++) {

            cout << adj[i][j];
            if (j < adj[i].size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}


int main () {

    n = 5;

    add_edge(0, 1);
    add_edge(0, 3);

    add_edge(1, 2);
    add_edge(2, 3);
    add_edge(4, 1);


    add_weighted_edge(0, 1, 5);
    add_weighted_edge(0, 3, 3);
    add_weighted_edge(1, 2, 7);
    add_weighted_edge(2, 3, 2);

    print_weighted_list();
    // 0 -> 1 -> 3


    // print_list();


    // cout << "\nNeighbors of vertex 0: ";

    // for (int i = 0; i < adj[0].size(); i++) {
    //     cout << adj[0][i] << " ";
    // }
    return 0;
}
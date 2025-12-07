#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

struct DSU {
    vector<int> parent;
    
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans(n + 1);
    
    ans[n] = 0;

    vector<bool> active(n + 1, false);
    DSU dsu(n);
    int current_components = 0;
    for (int i = n; i > 1; --i) {
        current_components++;
        active[i] = true;
        
  
        for (int neighbor : adj[i]) {
            if (active[neighbor]) {
                if (dsu.unite(i, neighbor)) {
                    current_components--;
                }
            }
        }
        
        ans[i - 1] = current_components;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
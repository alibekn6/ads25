#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> parent;
vector<int> min_val;

int find_set(int i) { // 5
    if (parent[i] == i) // parent[5] == 5
        return i;
    return parent[i] = find_set(parent[i]);
}

void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        parent[b] = a;
        min_val[a] = min(min_val[a], min_val[b]);
    }

}

vector<vector<int>> adj;
vector<int> tree_parent;
vector<int> child_count;

void dfs(int u, int parent_node) {
    tree_parent[u] = parent_node;

    for (int v : adj[u]) {
        if (v != parent_node) {
            child_count[u]++;
            dfs(v, u);
        }
    }
}


void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;


    adj.resize(n + 1);
    parent.resize(n + 1);
    min_val.resize(n + 1);
    tree_parent.resize(n + 1, 0);
    child_count.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        min_val[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        unite_sets(u, v);
    }

    map<int, bool> component_roots;

    for (int i = 1; i <= n; ++i) {
        int root_repr = find_set(i);
        component_roots[min_val[root_repr]] = true;
    }


    for (auto const& [root, _] : component_roots) {
        dfs(root, 0);
    }

    int big_fam_count = 0;

    for (int i = 1; i <= n; i++) {
        bool is_root = (tree_parent[i] == 0);

        if (is_root) {
            big_fam_count++;
        } else {
            int p = tree_parent[i];
            if (child_count[i] > child_count[p]) {
                big_fam_count++;
            }
        }
    }

    cout << big_fam_count << endl;


}



int main () {
    

    solve();

    return 0;
}
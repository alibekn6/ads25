#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> parent;
vector<int> min_val;

int find_set(int i) {
    if (parent[i] == i)
        return i;
    parent[i] = find_set(parent[i])
    return parent[i];
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

void dfs_tree_structure(int u, int parent_node) {
    tree_parent[u] = parent_node;

    for (int v : adj[u]) {
        if (v != parent_node) {
            child_count[u]++;
            dfs_tree_structure(v, u);
        }
    }
}

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    adj.resize(N + 1);
    parent.resize(N + 1);
    min_val.resize(N + 1);
    tree_parent.resize(N + 1, 0);
    child_count.resize(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        min_val[i] = i;
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        unite_sets(u, v);
    }

    map<int, bool> component_roots;
    for (int i = 1; i <= N; ++i) {
        int root_repr = find_set(i);
        component_roots[min_val[root_repr]] = true;
    }

    for (auto const& [root, _] : component_roots) {
        dfs_tree_structure(root, 0); 
    }

    int big_fam_count = 0;
    
    for (int i = 1; i <= N; ++i) {
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
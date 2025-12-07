#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;




const long long INF = 1e18;

vector<long long> tree;
long long total_cost = 0;


// start = 1,  end = 9

// l = 1, r = 3

void update(int node, int start, int end, int l, int r, int val) {
    
    // check out of bound
    if (l > end || r < start) return;
    


    if (l <= start && end <= r) {
        tree[node] = min(tree[node], (long long)val);
        return;
    }
    
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
}


void solve(int node, int start, int end, long long current_min) {
    current_min = min(current_min, tree[node]);
    
    if (start == end) {
        total_cost += current_min;
        return;
    }
    
    int mid = (start + end) / 2;
    solve(2 * node, start, mid, current_min);
    solve(2 * node + 1, mid + 1, end, current_min);
}


int main () {

    int n, m;
    if (!(cin >> n >> m)) return 0;


    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }


    int n_edges = n - 1;

    tree.assign(4 * n, INF);

    for (int i = 0; i < m; i++) {
        int l, r, c;

        cin >> l >> r >> c;

        if (l < r) {
            update(1, 1, n_edges, l, r-1, c);
        }
    }

    solve(1, 1, n_edges, INF);

    cout << total_cost;

    return 0;
}
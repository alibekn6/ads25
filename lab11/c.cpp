using namespace std;
#include <vector>
#include <iostream>


class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        
        if (px == py) return false;
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    int x, y; // cost per km for big and small vehicles
    cin >> x >> y;
    
    vector<pair<long long, pair<int, int>>> edges; // {cost, {u, v}}
    
    for (int i = 0; i < m; i++) {
        string type;
        int a, b, c;
        cin >> type >> a >> b >> c;
        
        long long cost;
        if (type == "big") {
            cost = (long long)x * c;
        } else if (type == "small") {
            cost = (long long)y * c;
        } else { // "both"
            cost = (long long)min(x, y) * c;
        }
        
        edges.push_back({cost, {a, b}});
    }
    
    // Sort edges by cost (Kruskal's algorithm)
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    long long totalCost = 0;
    int edgesUsed = 0;
    
    for (auto& edge : edges) {
        long long cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        
        if (dsu.unite(u, v)) {
            totalCost += cost;
            edgesUsed++;
            
            // MST needs exactly n-1 edges
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}
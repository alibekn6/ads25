#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    

    vector<vector<pair<int, long long>>> adj(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dist = abs(cities[i].first - cities[j].first) + 
                            abs(cities[i].second - cities[j].second);
            adj[i].push_back({j, dist});
            adj[j].push_back({i, dist});
        }
    }
    
    vector<long long> minMaxAge(n, LLONG_MAX);
    priority_queue<pair<long long, int>, 
                   vector<pair<long long, int>>, 
                   greater<pair<long long, int>>> pq;
    
    minMaxAge[0] = 0;
    pq.push({0, 0}); // {max_age_so_far, city}
    
    while (!pq.empty()) {
        auto [maxAge, u] = pq.top();
        pq.pop();
        
        if (u == n - 1) {
            cout << maxAge << endl;
            return 0;
        }
        
        if (maxAge > minMaxAge[u]) continue;
        
        for (auto [v, edgeWeight] : adj[u]) {
            long long newMaxAge = max(maxAge, edgeWeight);
            
            if (newMaxAge < minMaxAge[v]) {
                minMaxAge[v] = newMaxAge;
                pq.push({newMaxAge, v});
            }
        }
    }
    
    cout << minMaxAge[n - 1] << endl;
    
    return 0;
}
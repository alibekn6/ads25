#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> queries(t);
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    map<int, pair<int, int> > positions;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val;
            cin >> val;
            positions[val] = make_pair(i, j);
        }
    }

    for (int i = 0; i < t; i++) {
        int q = queries[i];
        if (positions.find(q) != positions.end()) {
            cout << positions[q].first << " " << positions[q].second << "\n";
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}

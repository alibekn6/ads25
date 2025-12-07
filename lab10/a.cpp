#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main () {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    queue<tuple<int, int, int>> q;
    int mushrooms = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) q.emplace(i, j, 0);
            else if (a[i][j] == 1) mushrooms++;
            
        }
    }

    if (mushrooms == 0) {
        cout << 0;
        return 0;
    }

    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int t = 0;

    while (!q.empty()) {
        auto [x, y, time] = q.front(); // first -> 0, 0, 0
        q.pop(); // remove first, 
        t = time; // t = 0
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] == 1) {
                a[nx][ny] = 2;
                mushrooms--;
                q.emplace(nx, ny, time + 1);
            }

        }

    }

    cout << (mushrooms == 0 ? t : -1);

    return 0;
}
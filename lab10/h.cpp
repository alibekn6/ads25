#include <iostream>
using namespace std;

int main () {

    int n, m;
    cin >> n >> m;
    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};


    int cnt = 0;

    function<void(int, int)> dfs = [&] (int x, int y) {
        vis[x][y] = 1;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == '1') {
                dfs(nx, ny);
            }
        }
    };


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;

}
#include<bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_valid(int x, int y, int m, int n) {
    return x >= 0 && y >= 0 && x < m && y < n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<int>> visited(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }

    int minutes = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            pair<int, int> cur = q.front();
            q.pop();
            for(int i=0; i<4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(is_valid(nx, ny, m, n) && grid[nx][ny] != 0 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        if(!q.empty()) {
            minutes++;
        }
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    cout << minutes << endl;
    return 0;
}
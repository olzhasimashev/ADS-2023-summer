#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<vector<char>>& grid, int i, int j) {
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0') 
        return;
    grid[i][j] = '0';
    for(auto& d: dir)
        dfs(grid, i + d[0], j + d[1]);
}

int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for(int i = 0; i<grid.size(); i++) {
        for(int j = 0; j<grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << numIslands(grid) << "\n";
    return 0;
}
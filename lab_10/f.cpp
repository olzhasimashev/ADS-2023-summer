#include <vector>
#include <iostream>
using namespace std;

vector<int> adj[100001];
bool visited[100001];

void dfs(int node) {
    visited[node] = true;
    for(int i = 0; i < adj[node].size(); i++) {
        int next_node = adj[node][i];
        if(!visited[next_node]) {
            dfs(next_node);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        visited[i] = false;
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }

    int s, f;
    cin >> s >> f;

    dfs(s);

    if(visited[f]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
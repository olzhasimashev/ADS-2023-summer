#include<bits/stdc++.h>
using namespace std;

vector<int> g[501];
bool vis[501], rec[501];
pair<int, int> cycleEdge;

bool isCyclic(int v) {
    vis[v] = true;
    rec[v] = true;
    for(int u : g[v]) {
        if(!vis[u]) {
            if(isCyclic(u)) {
                if(vis[v]) cycleEdge = {v, u};
                return true;
            }
        } else if(rec[u]) {
            cycleEdge = {v, u};
            return true;
        }
    }
    rec[v] = false;
    return false;
}

bool isCyclicUtil(int n) {
    fill(vis, vis+n+1, false);
    fill(rec, rec+n+1, false);
    for(int i = 1; i <= n; ++i) {
        if(!vis[i] && isCyclic(i))
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        edges[i] = {u, v};
    }
    for(auto edge : edges) {
        int u = edge.first, v = edge.second;
        g[u].erase(remove(g[u].begin(), g[u].end(), v), g[u].end());
        if(!isCyclicUtil(n)) {
            cout << "YES" << endl;
            return 0;
        }
        g[u].push_back(v);
    }
    cout << "NO" << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> g[N], edges[N];
int par[N], sz[N], ans[N], vis[N];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    int cc = 0;
    for(int i = n; i >= 1; i--) {
        vis[i] = 1;
        cc++;
        for(auto j: edges[i]) {
            if(vis[j]) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
        for(auto j: g[i]) {
            if(find(i) != find(j)) {
                merge(i, j);
                cc--;
            }
        }
        ans[i] = cc;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
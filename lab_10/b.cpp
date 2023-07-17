#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;
    --start; --end; // to make 0-indexed

    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i=0; i<n; i++) {
            if(graph[node][i] && dist[i] == -1) {
                dist[i] = dist[node] + 1;
                q.push(i);
            }
        }
    }

    cout << dist[end] << endl;

    return 0;
}
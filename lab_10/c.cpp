#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    cin >> A >> B;

    vector<int> dist(20001, -1), parent(20001, -1), op(20001);
    dist[A] = 0;
    queue<int> q;
    q.push(A);

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        if(v == B)
            break;

        int nv = v * 2;
        if(nv <= 20000 && dist[nv] == -1) {
            dist[nv] = dist[v] + 1;
            parent[nv] = v;
            op[nv] = 2;
            q.push(nv);
        }

        nv = v - 1;
        if(nv >= 0 && dist[nv] == -1) {
            dist[nv] = dist[v] + 1;
            parent[nv] = v;
            op[nv] = 1;
            q.push(nv);
        }
    }

    vector<int> path;
    for(int v = B; v != A; v = parent[v]) {
        path.push_back(v);
    }

    cout << dist[B] << endl;
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }

    return 0;
}
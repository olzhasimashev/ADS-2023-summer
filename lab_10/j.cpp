#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> numChildren(n + 1, 0);
    std::vector<bool> visited(n + 1, false);
    std::vector<int> parent(n + 1, 0);
    std::vector<int> root(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            std::queue<int> q;
            int r = i;
            q.push(i);

            while (!q.empty()) {
                int v = q.front();
                q.pop();
                visited[v] = true;
                r = std::min(r, v);

                for (int u : graph[v]) {
                    if (!visited[u]) {
                        q.push(u);
                        parent[u] = v;
                    }
                }
            }

            // Now, r is the root of the connected component
            q.push(r);
            visited.assign(n + 1, false);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                visited[v] = true;
                root[v] = r;

                for (int u : graph[v]) {
                    if (!visited[u]) {
                        q.push(u);
                        numChildren[v]++;
                    }
                }
            }
        }
    }

    int bigFamCount = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == root[i] || numChildren[i] > numChildren[parent[i]]) {
            bigFamCount++;
        }
    }

    std::cout << bigFamCount << std::endl;

    return 0;
}
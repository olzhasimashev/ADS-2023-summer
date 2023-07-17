#include <iostream>
#include <vector>
#include <stack>

int n, m;
std::vector<std::vector<int>> adj;
std::vector<int> visited;
std::stack<int> result;

bool dfs(int v) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (visited[u] == 1) {
            return true; // cycle detected
        } else if (visited[u] == 0) {
            if (dfs(u)) return true;
        }
    }
    visited[v] = 2;
    result.push(v);
    return false;
}

int main() {
    std::cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        adj[x].push_back(y);
    }

    bool isCycle = false;
    for (int i = 1; i <= n; ++i) {
        if (visited[i] == 0) {
            if (dfs(i)) {
                isCycle = true;
                break;
            }
        }
    }

    if (isCycle) {
        std::cout << "Impossible" << std::endl;
    } else {
        std::cout << "Possible" << std::endl;
        while (!result.empty()) {
            std::cout << result.top() << " ";
            result.pop();
        }
    }

    return 0;
}
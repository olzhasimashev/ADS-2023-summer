#include <iostream>
#include <vector>
#include <queue>
#include <limits>

const int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, q;
    std::cin >> n >> m >> q;
    
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> distanceToRed(n + 1, INF);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::queue<std::pair<int, int>> bfsQueue;

    for (int i = 0; i < q; ++i) {
        int queryType, v;
        std::cin >> queryType >> v;

        if (queryType == 1) {
            if (distanceToRed[v] > 0) {
                bfsQueue.push({v, 0});
            }
        } else {
            while (!bfsQueue.empty()) {
                int vertex = bfsQueue.front().first;
                int dist = bfsQueue.front().second;
                bfsQueue.pop();

                if (dist < distanceToRed[vertex]) {
                    distanceToRed[vertex] = dist;

                    for (int u : graph[vertex]) {
                        if (dist + 1 < distanceToRed[u]) {
                            bfsQueue.push({u, dist + 1});
                        }
                    }
                }
            }

            std::cout << (distanceToRed[v] == INF ? -1 : distanceToRed[v]) << std::endl;
        }
    }

    return 0;
}
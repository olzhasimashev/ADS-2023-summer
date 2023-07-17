#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int u, v, cost;
    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

int find_set(int v, std::vector<int>& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}

void union_sets(int a, int b, std::vector<int>& parent, std::vector<int>& rank) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (rank[a] < rank[b])
            std::swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Edge> edges;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost;
            std::cin >> cost;
            if (i < j) {
                edges.push_back({i, j, cost});
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    std::vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    int totalCost = 0;
    for (const auto& e : edges) {
        if (find_set(e.u, parent) != find_set(e.v, parent)) {
            totalCost += e.cost;
            union_sets(e.u, e.v, parent, rank);
        }
    }

    std::cout << totalCost << std::endl;

    return 0;
}
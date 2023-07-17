#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Edge {
    int a, b, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
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
    int n, m, x, y;
    std::cin >> n >> m;
    std::cin >> x >> y;

    std::vector<Edge> edges;

    for (int i = 0; i < m; i++) {
        std::string type;
        int a, b, c;
        std::cin >> type >> a >> b >> c;
        int cost = 0;
        if (type == "both") cost = std::min(x, y) * c;
        else if (type == "big") cost = x * c;
        else cost = y * c;
        edges.push_back({a, b, cost});
    }

    std::sort(edges.begin(), edges.end());

    int totalCost = 0;
    std::vector<int> parent(n+1), rank(n+1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (Edge& e : edges) {
        if (find_set(e.a, parent) != find_set(e.b, parent)) {
            totalCost += e.weight;
            union_sets(e.a, e.b, parent, rank);
        }
    }

    std::cout << totalCost << std::endl;

    return 0;
}
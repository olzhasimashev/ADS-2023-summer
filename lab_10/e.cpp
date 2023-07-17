#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adjacency_matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> adjacency_matrix[i][j];
        }
    }

    // Process the queries
    for (int query = 0; query < q; ++query) {
        int x, y, z;
        std::cin >> x >> y >> z;
        --x; --y; --z; // Convert to 0-indexing

        // Check if the elements can be added together without exploding
        if (adjacency_matrix[x][y] && adjacency_matrix[y][z] && adjacency_matrix[z][x]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
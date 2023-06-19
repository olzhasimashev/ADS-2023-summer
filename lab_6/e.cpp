#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    
    // Read matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Sort each column in descending order
    for (int j = 0; j < m; ++j) {
        std::vector<int> column(n);
        for (int i = 0; i < n; ++i) {
            column[i] = matrix[i][j];
        }

        std::sort(column.begin(), column.end(), std::greater<int>());

        for (int i = 0; i < n; ++i) {
            matrix[i][j] = column[i];
        }
    }

    // Print matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
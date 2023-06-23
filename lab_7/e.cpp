#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, std::vector<int>>> rows;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        std::vector<int> row(m);
        for (int j = 0; j < m; ++j) {
            std::cin >> row[j];
            sum += row[j];
        }
        rows.push_back(std::make_pair(sum, row));
    }

    std::sort(rows.begin(), rows.end(), [](const std::pair<int, std::vector<int>>& a, const std::pair<int, std::vector<int>>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for (const auto& pair : rows) {
        for (int number : pair.second) {
            std::cout << number << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
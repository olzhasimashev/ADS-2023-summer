#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    
    std::cin >> n >> m;

    std::unordered_map<int, int> num_count;
    int number;
    for (int i = 0; i < n; ++i) {
        std::cin >> number;
        num_count[number]++;
    }

    std::vector<int> common_elements;

    for (int i = 0; i < m; ++i) {
        std::cin >> number;
        if (num_count[number] > 0) {
            common_elements.push_back(number);
            num_count[number]--;
        }
    }

    std::sort(common_elements.begin(), common_elements.end());

    for (int num : common_elements) {
        std::cout << num << " ";
    }

    return 0;
}
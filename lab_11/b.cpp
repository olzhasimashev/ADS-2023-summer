#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> ducks(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> ducks[i];
    }

    std::sort(ducks.begin(), ducks.end());

    long long totalCost = 0;
    for (int i = 0; i < n / 2; ++i) {
        totalCost += ducks[i] + ducks[n - i - 1];
        
    }

    for (int i = 0; i < n / 2; ++i) {
        totalCost += ducks[i];
        std::cout << i << std::endl;
    }

    if (n % 2 == 1) {
        totalCost += ducks[0] + ducks[n / 2];
    }

    std::cout << totalCost << std::endl;

    return 0;
}
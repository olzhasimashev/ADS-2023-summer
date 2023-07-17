#include <iostream>
#include <vector>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string input;
        int k;
        std::cin >> input >> k;

        std::string s = input + input;
        int n = s.size();
        
        std::vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; ++i) {
            if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }

        int period = input.size();
        for (int i = 1; i < input.size(); ++i) {
            if (z[input.size() + i] >= input.size() - i) {
                period = i;
                break;
            }
        }

        int ans = (k - 1) * period + input.size();
        std::cout << ans << std::endl;
    }

    return 0;
}
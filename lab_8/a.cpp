#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

const long long MOD = 1e9 + 7;

long long compute_hash(const std::string& s) {
    long long hash = 0;
    long long power = 1;
    for (char ch : s) {
        hash = (hash + (ch - 47) * power) % MOD;
        power = (power * 11) % MOD;
    }
    return hash;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> inputs(2 * N);
    std::unordered_map<long long, std::string> hashes;
    std::vector<std::string> output;
    
    for (int i = 0; i < 2 * N; ++i) {
        std::cin >> inputs[i];
        if (std::all_of(inputs[i].begin(), inputs[i].end(), ::isdigit)) {
            long long hash = compute_hash(inputs[i]);
            hashes[hash] = inputs[i];
        }
    }

    // Try to match each hash with the numbers
    for (int i = 0; i < 2 * N; ++i) {
        if (!std::all_of(inputs[i].begin(), inputs[i].end(), ::isdigit)) {
            continue;
        }
        long long number;
        try {
            number = std::stoll(inputs[i]);
        } catch (...) {
            continue;
        }
        if (hashes.find(number) != hashes.end()) {
            output.push_back("Hash of string \"" + hashes[number] + "\" is " + std::to_string(number));
        }
    }

    // Shift and output in the desired order
    if (!output.empty()) {
        std::cout << output.back() << std::endl;
        for (size_t i = 0; i < output.size() - 1; ++i) {
            std::cout << output[i] << std::endl;
        }
    }

    return 0;
}

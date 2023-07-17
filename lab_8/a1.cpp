#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const long long MOD = 1000000007;

long long calculateHash(const std::string &s) {
    long long hash = 0;
    long long power = 1;
    for (char ch : s) {
        hash = (hash + (ch - 47) * power) % MOD;
        power = (power * 11) % MOD;
    }
    return hash;
}

bool isNumber(const std::string &s) {
    for (char ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

long long stringToLongLong(const std::string &s) {
    long long result = 0;
    for (char ch : s) {
        result = result * 10 + (ch - '0');
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> strings;
    std::unordered_map<long long, int> hashes;
    
    for (int i = 0; i < 2 * N; ++i) {
        std::string element;
        std::cin >> element;
        
        if (isNumber(element)) {
            hashes[stringToLongLong(element)] = i;
        } else {
            strings.push_back(element);
        }
    }

    for (const auto& str : strings) {
        long long hash = calculateHash(str);
        if (hashes.find(hash) == hashes.end()) {
            std::cout << "Hash of string \"" << str << "\" is " << hash << "\n";
        }
    }

    return 0;
}
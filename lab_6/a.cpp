#include <iostream>
#include <queue>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::priority_queue<char, std::vector<char>, std::greater<char>> vowels, consonants;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels.push(c);
        } else {
            consonants.push(c);
        }
    }

    while (!vowels.empty()) {
        std::cout << vowels.top();
        vowels.pop();
    }

    while (!consonants.empty()) {
        std::cout << consonants.top();
        consonants.pop();
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareLength(const std::string &a, const std::string &b) {
    return a.length() < b.length();
}

int main() {
    int T;
    std::cin >> T;
    
    std::cin.ignore();
    
    for (int i = 0; i < T; ++i) {
        std::string input;
        std::getline(std::cin, input);
        
        std::vector<std::string> strings;
        std::string word;
        size_t pos;
        while ((pos = input.find(' ')) != std::string::npos) {
            word = input.substr(0, pos);
            strings.push_back(word);
            input.erase(0, pos + 1);
        }
        strings.push_back(input);

        std::stable_sort(strings.begin(), strings.end(), compareLength);
        
        for (size_t j = 0; j < strings.size(); ++j) {
            std::cout << strings[j];
            if (j < strings.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}
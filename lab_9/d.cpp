#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string toLowerCase(const std::string &str) {
    std::string lowerStr = str;
    for (char &ch : lowerStr) {
        ch = std::tolower(ch);
    }
    return lowerStr;
}

std::string capitalizeFirstLetter(const std::string &str) {
    std::string capitalizedStr = str;
    if (!capitalizedStr.empty()) {
        capitalizedStr[0] = std::toupper(capitalizedStr[0]);
    }
    return capitalizedStr;
}

int main() {
    std::string prevCityName;
    std::cin >> prevCityName;
    prevCityName = toLowerCase(prevCityName);

    int n;
    std::cin >> n;

    std::vector<std::string> cityNames(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cityNames[i];
        cityNames[i] = toLowerCase(cityNames[i]);
    }

    std::vector<std::string> possibleCities;
    int maxSuffixLength = 0;

    for (int i = 0; i < n; i++) {
        const auto &cityName = cityNames[i];
        int suffixLength = 0;
        int minLength = std::min(cityName.length(), prevCityName.length());

        for (int j = 1; j <= minLength; j++) {
            if (cityName.substr(0, j) == prevCityName.substr(prevCityName.length() - j)) {
                suffixLength = j;
            }
        }

        if (suffixLength > maxSuffixLength) {
            maxSuffixLength = suffixLength;
            possibleCities.clear();
            possibleCities.push_back(cityName);
        } else if (suffixLength == maxSuffixLength && maxSuffixLength > 0) {
            possibleCities.push_back(cityName);
        }
    }

    std::cout << possibleCities.size() << std::endl;
    for (const auto &city : possibleCities) {
        std::cout << capitalizeFirstLetter(city) << std::endl;
    }

    return 0;
}
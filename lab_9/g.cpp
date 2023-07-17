#include <bits/stdc++.h>

using namespace std;

vector<size_t> computeFunction(string str){
    size_t n = str.size();
    vector<size_t> pi(n);
    pi[0] = 0;
    for(size_t i = 1; i < n; i++) {
        size_t j = pi[i - 1];
        while(j > 0 && str[j] != str[i]) {
            j = pi[j - 1];
        }
        if(str[j] == str[i]) {
            pi[i] = j + 1;
        }
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    vector<size_t> pi = computeFunction(s);
    cout << s.size() - pi[s.size() - 1];
    return 0;
}
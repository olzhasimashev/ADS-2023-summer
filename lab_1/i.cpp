#include <bits/stdc++.h>
using namespace std;

string solve(int n, string s) {
    deque<int> S, K;
    for (int i = 0; i < n; ++i) {
        (s[i] == 'S' ? S : K).push_back(i);
    }
    while (!S.empty() && !K.empty()) {
        if (S.front() < K.front()) {
            K.pop_front();
            S.push_back(S.front() + n);
            S.pop_front();
        } else {
            S.pop_front();
            K.push_back(K.front() + n);
            K.pop_front();
        }
    }
    return (S.empty() ? "KATSURAGI" : "SAKAYANAGI");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    string votes;
    cin >> votes;
    
    cout << solve(n, votes) << endl;
    return 0;
}
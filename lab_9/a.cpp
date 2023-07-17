#include<bits/stdc++.h>
using namespace std;

int repeatedStringMatch(string A, string B) {
    string temp = A;
    int count = 1;

    while(temp.length() < B.length()) {
        temp += A;
        count++;
    }
    
    if (temp.find(B) != string::npos) return count;
    temp += A;
    return (temp.find(B) != string::npos) ? count + 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    cin >> A >> B;

    cout << repeatedStringMatch(A, B) << "\n";

    return 0;
}
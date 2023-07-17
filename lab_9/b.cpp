#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string password, paper;
    int K;
    cin >> password >> K;
    cin.ignore();
    getline(cin, paper);

    int count = 0;
    size_t pos = paper.find(password, 0);
    while(pos != string::npos)
    {
        count++;
        pos = paper.find(password, pos + 1);
    }

    if(count >= K)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;
}
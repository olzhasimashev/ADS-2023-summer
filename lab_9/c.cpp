#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << -1 << endl;
        return 0;
    }
    string temp = s1;
    for (int i = 0; i < s1.length(); i++) {
        if (temp == s2) {
            cout << i << endl;
            return 0;
        }
        temp = temp[temp.length() - 1] + temp.substr(0, temp.length() - 1);
    }
    cout << -1 << endl;
    return 0;
}
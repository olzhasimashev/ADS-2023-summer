#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> find_positions(const string &text, const string &pattern) {
    vector<int> positions;
    size_t pos = text.find(pattern, 0);
    while(pos != string::npos) {
        positions.push_back(pos);
        pos = text.find(pattern, pos + 1);
    }
    return positions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    vector<int> positions1 = find_positions(s1, t);
    set<int> positions2(find_positions(s2, t).begin(), find_positions(s2, t).end());

    int count = 0;
    for (int pos : positions1) {
        if (positions2.count(pos)) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}
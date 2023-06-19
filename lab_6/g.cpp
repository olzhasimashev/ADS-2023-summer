#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, string> nickname_change;
    map<string, string> original_to_new;
    for(int i = 0; i < n; i++) {
        string old_nick, new_nick;
        cin >> old_nick >> new_nick;
        if(nickname_change.find(old_nick) == nickname_change.end()) {
            original_to_new[old_nick] = new_nick;
        } else {
            string original = nickname_change[old_nick];
            original_to_new[original] = new_nick;
        }
        nickname_change[new_nick] = nickname_change[old_nick].empty() ? old_nick : nickname_change[old_nick];
    }

    cout << original_to_new.size() << endl;
    for(auto& pair : original_to_new) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}
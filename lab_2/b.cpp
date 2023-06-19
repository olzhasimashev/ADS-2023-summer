#include <iostream>
#include <list>
#include <string>

using namespace std;

void print(list<string>& lst) {
    for(auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    int N, K;
    cin >> N >> K;
    list<string> words;
    string word;
    for (int i = 0; i < N; i++) {
        cin >> word;
        words.push_back(word);
    }

    while(K--) {
        words.push_back(words.front());
        words.pop_front();
    }
    
    print(words);

    return 0;
}
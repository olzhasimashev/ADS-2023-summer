#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    int q, k;
    cin >> q >> k;
    priority_queue<ll> pq;
    ll total = 0;
    
    while (q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            ll n;
            cin >> n;
            pq.push(-n);
            total += n;
            if (pq.size() > k) {
                total += pq.top();
                pq.pop();
            }
        } else {
            cout << total << '\n';
        }
    }

    return 0;
}
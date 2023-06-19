#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll> > pq;

    for(int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    ll res = 0;
    while(pq.size() > 1) {
        ll a = pq.top();
        pq.pop();

        ll b = pq.top();
        pq.pop();

        res += a + b;
        pq.push(a + b);
    }

    cout << res;

    return 0;
}
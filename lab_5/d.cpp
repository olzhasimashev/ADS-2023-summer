#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        pq.push(a);
    }

    ll res = 0;

    while(pq.top() < m && pq.size() > 1) {
        ll least = pq.top();
        pq.pop();
        ll second_least = pq.top();
        pq.pop();
        pq.push(least + 2 * second_least);
        res++;
    }

    if(pq.top() < m) {
        cout << "-1";
    }
    else {
        cout << res;
    }

    return 0;
}
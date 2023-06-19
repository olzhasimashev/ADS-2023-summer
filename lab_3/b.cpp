#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> a;

bool check(ll x) {
    int cnt = 1;
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        if(sum + a[i] > x) {
            sum = a[i];
            ++cnt;
        } else {
            sum += a[i];
        }
    }
    return cnt <= k;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    ll lb = 0, ub = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        lb = max(lb, (ll)a[i]);
        ub += a[i];
    }
    while(lb < ub) {
        ll mid = lb + (ub - lb) / 2;
        if(check(mid)) {
            ub = mid;
        } else {
            lb = mid + 1;
        }
    }
    cout << lb << '\n';
    return 0;
}
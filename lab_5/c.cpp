#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    priority_queue<int> pq;

    for(int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }

    long long res = 0;

    while(x--) {
        int top = pq.top();
        pq.pop();
        res += top;
        pq.push(top - 1);
    }

    cout << res;

    return 0;
}
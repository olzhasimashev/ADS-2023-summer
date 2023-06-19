#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_pastures(int length, vector<pair<int,int>>& pastures) {
    int count = 0;
    for (auto& pasture : pastures) {
        if (max(pasture.first, pasture.second) <= length) {
            count++;
        }
    }
    return count;
}

int min_paddock_length(int n, int k, vector<pair<int,int>>& pastures) {
    int left = 0;
    int right = 1e9 + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (count_pastures(mid, pastures) >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> pastures(n);
    for (int i = 0; i < n; i++) {
        int xi1, yi1, xi2, yi2;
        cin >> xi1 >> yi1 >> xi2 >> yi2;
        pastures[i] = make_pair(max(xi2, yi2), min(xi1, yi1));
    }
    sort(pastures.rbegin(), pastures.rend());
    cout << min_paddock_length(n, k, pastures) << endl;
    return 0;
}
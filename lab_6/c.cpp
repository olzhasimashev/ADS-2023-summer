#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> points(N);
    for (int i = 0; i < N; i++)
        cin >> points[i];
    sort(points.begin(), points.end());

    int minDiff = INT_MAX;
    for (int i = 0; i < N - 1; i++) {
        minDiff = min(minDiff, points[i + 1] - points[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        if (points[i + 1] - points[i] == minDiff)
            cout << points[i] << " " << points[i + 1] << " ";
    }

    cout << endl;
    return 0;
}
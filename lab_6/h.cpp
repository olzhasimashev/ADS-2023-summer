#include<bits/stdc++.h>
using namespace std;

char balancedChar(vector<char>& arr, char c) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(arr[mid] > c) {
            if(mid == 0 || arr[mid-1] <= c) return arr[mid];
            else r = mid - 1;
        }
        else l = mid + 1;
    }
    return arr[0];
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    char c;
    cin >> c;

    cout << balancedChar(arr, c) << endl;

    return 0;
}
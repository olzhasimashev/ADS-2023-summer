#include <bits/stdc++.h>
using namespace std;

void makeBalancedBST(vector<int>& arr, int low, int high, vector<int>& res) {
    if (low > high) return;
    
    int mid = low + (high - low) / 2;
    res.push_back(arr[mid]);
    
    makeBalancedBST(arr, low, mid - 1, res);
    makeBalancedBST(arr, mid + 1, high, res);
}

int main() {
    int N;
    cin >> N;
    int size = (1 << N) - 1;
    vector<int> arr(size);
    
    for (int& element : arr) {
        cin >> element;
    }

    sort(arr.begin(), arr.end());
    
    vector<int> res;
    makeBalancedBST(arr, 0, size - 1, res);
    
    for (int element : res) {
        cout << element << " ";
    }

    return 0;
}
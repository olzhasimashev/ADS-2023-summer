#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    multiset<int> set1, set2;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        set1.insert(num);
    }
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        set2.insert(num);
    }
    for(auto &num : set1){
        if(set2.count(num) > 0){
            cout << num << " ";
            set2.erase(set2.lower_bound(num));
        }
    }
    return 0;
}
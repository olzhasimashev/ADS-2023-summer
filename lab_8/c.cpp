#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;
const long long MOD = 1e9+7;
long long power[MAX], hash_val[MAX], inv[MAX];

long long fast_power(long long base, long long expo) {
    if(expo == 0)
        return 1;
    else if(expo % 2 == 0) {
        long long root = fast_power(base, expo/2);
        return root*root % MOD;
    }
    else {
        return base * fast_power(base, expo-1) % MOD;
    }
}

void precompute() {
    power[0] = 1;
    for(int i = 1; i < MAX; i++) {
        power[i] = power[i-1]*31 % MOD;
    }
    long long power_inv = fast_power(31, MOD-2);
    inv[0] = 1;
    for(int i = 1; i < MAX; i++) {
        inv[i] = inv[i-1]*power_inv % MOD;
    }
}

void compute_hash(string &s) {
    int n = s.size();
    hash_val[0] = 0;
    for(int i = 1; i <= n; i++) {
        hash_val[i] = (hash_val[i-1] + power[i-1]*(s[i-1]-'a'+1)) % MOD;
    }
}

long long get_hash(int l, int r) {
    return ((hash_val[r+1] - hash_val[l] + MOD) % MOD * inv[l]) % MOD;
}

int main() {
    precompute();
    string s;
    cin >> s;
    int n;
    cin >> n;

    compute_hash(s);

    unordered_map<long long, int> hash_count;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            hash_count[get_hash(i, j)]++;
        }
    }

    bool possible = true;
    while(n--) {
        string t;
        cin >> t;
        compute_hash(t);
        if(hash_count[get_hash(0, t.size()-1)]-- <= 0) {
            possible = false;
            break;
        }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
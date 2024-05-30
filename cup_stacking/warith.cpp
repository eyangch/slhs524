// Cup Stacking

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = (int) (1e9 + 7);

signed main() {
    int N; cin >> N;
    int T = N * (N+1) >> 1;
    
    int ans = 0;
    for (int i = 0; i < T; i++) {
        int x; cin >> x;
        ans = (ans + x) % MOD;
    }
    
    int fact = 1, config = 0;
    for (int i = 1; i < T; i++) {
        fact = (fact * i) % MOD;
    }
    for (int i = 0; i < N; i++) {
        int v = (fact * (i + 1)) % MOD;
        v = (v * (N - i)) % MOD;
        config = (config + v) % MOD;
    }
    
    cout << (ans * config) % MOD << '\n';
}
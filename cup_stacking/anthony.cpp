// created: 05-29-2024 Wed 11:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int m = n * (n+1) >> 1;
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        ll tmp; cin >> tmp; sum += tmp; sum %= MOD;
    }
    ll multiplier = 0;
    for (int i = 1; i <= n; i++) {
        multiplier += (ll)i * (n + 1 - i); multiplier %= MOD;
    }
    for (int i = 1; i < m; i++) {
        multiplier *= i; multiplier %= MOD;
    }
    cout << sum * multiplier % MOD << '\n';
    return 0;
}

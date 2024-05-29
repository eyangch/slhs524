// created: 05-20-2024 Mon 01:25 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MX = 1'000'000;
const int MOD = 1'000'000'007;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    auto fexp = [&](ll a, int b) {
        ll res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD; b >>= 1;
        }
        return res;
    };
    auto inv = [&](ll a) { return fexp(a, MOD - 2); };
    array<ll, MX+1> fac, ifac;
    fac[0] = 1;
    for (int i = 1; i <= MX; i++) fac[i] = fac[i-1] * i % MOD;
    ifac[MX] = inv(fac[MX]);
    for (int i = MX-1; i >= 0; i--) ifac[i] = ifac[i+1] * (i+1) % MOD;
    auto choose = [&](int n, int k) { return fac[n] * ifac[k] % MOD * ifac[n-k] % MOD; };
    int n, k; cin >> n >> k;
    ll ans = fexp(k+1, n);
    for (int i = 1; i <= k; i++) {
        ll add = choose(k, i) * fexp(k-i+1, n) % MOD;
        if (i % 2 == 1) add = -add;
        ans += add; ans %= MOD;
        if (ans < 0) ans += MOD;
    }
    cout << ans << '\n';
    return 0;
}
// created: 05-29-2024 Wed 11:34 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int meb(int x) {
    for (int i = 0; i <= 30; i++) if ((x & (1 << i)) == 0) return i+1;
    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    for (int i = 1; i < n; i++) a[i] ^= a[i-1];
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += meb(a[i]);
        for (int j = 0; j < i; j++) ans += meb(a[i] ^ a[j]);
    }
    cout << ans << '\n';
    return 0;
}

// created: 05-29-2024 Wed 09:15 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, q; cin >> n >> k >> q;
    V<ll> s(n, 0);
    for (int i = 1; i < n; i++) {
        cin >> s[i];
        s[i] += s[i-1];
    }
    V<ll> points(n); points[0] = 0;
    for (int i = 1; i < n; i++) points[i] = points[i-1] + (ll)i * (s[i] - s[i-1]);
    while (q--) {
        int m; cin >> m;
        V<int> t(m+2); t[0] = 0;
        for (int i = 1; i <= m; i++) cin >> t[i];
        t[m+1] = k+1;
        V<int> chunks(m+1);
        for (int i = 0; i < m+1; i++) chunks[i] = t[i+1] - t[i] - 1;
        ll ans = 0;
        for (int i : chunks) {
            int idx = prev(upper_bound(begin(s), end(s), i)) - begin(s);
            ans += points[idx];
            ans += (ll)(i - s[idx]) * (idx + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}

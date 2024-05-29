// created: 05-20-2024 Mon 01:25 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<V<int>> a(n, V<int>(k));
    for (int i = 0; i < n; i++) for (int j = 0; j < k; j++) cin >> a[i][j];
    ll ans = 0;
    for (int mask = 0; mask < 1<<k; mask++) {
        V<ll> stuff(n);
        for (int i = 0; i < n; i++) {
            ll num = 0;
            for (int j = 0; j < k; j++) {
                if (mask & (1 << j)) num += a[i][j];
                else num -= a[i][j];
            }
            stuff[i] = num;
        }
        ans = max(ans, *max_element(begin(stuff), end(stuff)) - *min_element(begin(stuff), end(stuff)));
    }
    cout << ans << '\n';
    return 0;
}
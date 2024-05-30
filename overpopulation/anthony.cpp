// created: 05-29-2024 Wed 10:39 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    V<int> freq(n+m+1, 0);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) freq[i+j]++;
    ll ans = 0;
    for (int i = 0; i <= n+m; i++) {
        ll avg = k / freq[i], leftover = k % freq[i];
        ans += (avg+1)*(avg+1)*leftover + avg*avg*(freq[i]-leftover);
    }
    cout << ans << '\n';
    return 0;
}

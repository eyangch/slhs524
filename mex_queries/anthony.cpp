// created: 05-30-2024 Thu 11:18 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0]; a[i][1] = i;
    }
    sort(begin(a), end(a));
    V<array<int, 2>> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i][0]; qs[i][1] = i;
    }
    sort(begin(qs), end(qs));
    V<array<ll, 3>> ans(q);
    int ptr = 0, mn = n, mx = 0;
    for (array<int, 2> i : qs) {
        if (i[0] == 0) {
            if (a[0][0] == 0) {
                int l = a[0][1], r = n - 1 - l;
                if (n == 1) ans[i[1]] = {-1, -1, -1};
                else ans[i[1]] = {1, max(l, r), (ll)l * (l + 1) / 2 + (ll)r * (r + 1) / 2};
            } else ans[i[1]] = {1, n, (ll)n * (n + 1) / 2};
            continue;
        }
        while (ptr < n && a[ptr][0] < i[0]) {
            mn = min(mn, a[ptr][1]); mx = max(mx, a[ptr][1]);
            ptr++;
        }
        if (ptr == 0 || i[0] - a[ptr-1][0] != 1 || a[ptr-1][0] != ptr-1) {
            ans[i[1]] = {-1, -1, -1};
            continue;
        }
        int ex = -1;
        if (ptr < n && a[ptr][0] == i[0]) ex = a[ptr][1];
        if (mn < ex && ex < mx) {
            ans[i[1]] = {-1, -1, -1};
            continue;
        }
        ans[i[1]][0] = mx - mn + 1;
        if (ex == -1) {
            ans[i[1]][1] = n;
            ans[i[1]][2] = (ll)(mn + 1) * (n - mx);
        } else {
            if (mn > ex) {
                ans[i[1]][1] = n - 1 - ex;
                ans[i[1]][2] = (ll)(mn - ex) * (n - mx);
            } else {
                ans[i[1]][1] = ex;
                ans[i[1]][2] = (ll)(mn + 1) * (ex - mx);
            }
        }
    }
    for (array<ll, 3> i : ans) {
        if (i[0] == -1) cout << "-1\n";
        else cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
    }
    return 0;
}

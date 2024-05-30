// created: 05-29-2024 Wed 10:51 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    V<array<int, 2>> up, down;
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int d; cin >> d; d--;
            if (i < d) up.push_back({i, d});
            else down.push_back({d, i});
        }
    }
    auto solve = [&](V<array<int, 2>>& a) {
        V<int> p(n+1);
        for (array<int, 2> i : a) {
            p[i[0]]++; p[i[1]+1]--;
        }
        for (int i = 1; i <= n; i++) p[i] += p[i-1];
        return (*max_element(begin(p), end(p)) + k - 1) / k;
    };
    int nup = solve(up), ndown = solve(down);
    if (nup > ndown) cout << 2 * nup - 2 << '\n';
    else cout << 2 * ndown - 1 << '\n';
    return 0;
}

// created: 05-29-2024 Wed 10:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    V<V<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int leaves = 0;
    for (int i = 1; i < n; i++) if (sz(adj[i]) == 1) leaves++;
    int ans = sz(adj[0]) == 1 ? leaves - 1 : leaves - 2;
    cout << ans << '\n';
    return 0;
}

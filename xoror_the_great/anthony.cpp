// created: 05-29-2024 Wed 10:01 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--) {
        int n, x; cin >> n >> x;
        V<int> a(n);
        for (int& i : a) cin >> i;
        int cur1 = 0, cur2 = 0;
        for (int i : a) {
            cur2 ^= i;
            if ((cur2 | x) == x) {
                cur1 |= cur2; cur2 = 0;
            }
        }
        cur1 |= cur2;
        if (cur1 == x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

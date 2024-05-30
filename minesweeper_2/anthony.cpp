// created: 05-30-2024 Thu 12:21 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<V<short>> a(n-1, V<short>(n-1));
    for (int i = 0; i < n-1; i++) for (int j = 0; j < n-1; j++) cin >> a[i][j];
    for (int mask1 = 0; mask1 < 1<<n; mask1++) {
        for (int mask2 = 0; mask2 < 1<<n-1; mask2++) {
            V<V<short>> test(n, V<short>(n));
            for (int i = 0; i < n; i++) test[0][i] = (mask1 >> i) & 1;
            for (int i = 0; i < n-1; i++) test[i+1][0] = (mask2 >> i) & 1;
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < n; j++) {
                    test[i][j] = a[i-1][j-1] - test[i-1][j-1] - test[i][j-1] - test[i-1][j];
                    if (test[i][j] < 0 || test[i][j] > 1) goto fail;
                }
            }
            cout << n << '\n';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) cout << test[i][j] << " \n"[j == n-1];
            }
            return 0;
            fail:;
        }
    }
    return 0;
}

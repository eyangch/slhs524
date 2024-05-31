// fun fun testing

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

V<V<short>> anthony(int n, V<V<short>> a) {
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
            return test;
            fail:;
        }
    }
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T; // number of times to run this
    for (int tt = 1; tt <= T; ++tt) {
        srand(time(0)); // seed
        // first, pick a value for N
        int N = rand() % 7 + 2;
        // now, randomly form the initial matrix
        V<V<short>> mines(N, V<short>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                mines[i][j] = rand() % 2;
            }
        }
        // now form the matrix `a`
        V<V<short>> a(N-1, V<short>(N-1));
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N-1; j++) {
                // [i][j], [i][j+1], [i+1][j], [i+1][j+1]
                a[i][j] = mines[i][j] + mines[i+1][j] + mines[i][j+1] + mines[i+1][j+1];
            }
        }
        // now we want to pass this into Anthony's code
        V<V<short>> test = anthony(N, a);
        // now we must test whether this is valid
        bool b = true;
        for (int i = 0; i < N-1; i++) {
            for (int j = 0; j < N-1; j++) {
                b &= (a[i][j] == test[i][j] + test[i+1][j] + test[i][j+1] + test[i+1][j+1]);
            }
        }
        cout << "Case " << tt << " complete.\n";
        if (!b) {
            cout << "WA WA WA WA WA\n";
            cout << "Here is the matrix 'a'" << '\n';
            for (int i = 0; i < N-1; i++) {
                for (int j = 0; j < N-1; j++) {
                    cout << a[i][j] << ' ';
                }
                cout << '\n';
            }
            cout << "Here is the mine-map Anthony returned\n";
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << test[i][j] << ' ';
                }
                cout << '\n';
            }
            return 0;
        }
    }
}
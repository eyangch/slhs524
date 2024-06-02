// created: 06-02-2024 Sun 11:08 AM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

const int MOD = 1'000'000'007;
void mAdd(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    int pow2[10001]; pow2[0] = 1;
    for (int i = 1; i <= 10000; i++) pow2[i] = pow2[i-1] * 2 % MOD;
    int dp[101][101][101][2]; // # nodes, # even nodes, # nodes at maxd, parity maxd
    memset(dp, 0, sizeof dp); dp[1][1][1][0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l < 2; l++) {
                    ll bruh1 = pow2[k] - 1, bruh2 = bruh1;
                    for (int add = 1; add + i <= N; add++) {
                        ll ways = pow2[add * (add - 1) >> 1] * bruh2 % MOD * dp[i][j][k][l] % MOD;
                        if (l == 0) mAdd(dp[i+add][j][add][l^1], (int)ways);
                        else mAdd(dp[i+add][j+add][add][l^1], (int)ways);
                        bruh2 *= bruh1; bruh2 %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) for (int j = 0; j < 2; j++) mAdd(ans, dp[N][K][i][j]);
    cout << ans << '\n';
    return 0;
}

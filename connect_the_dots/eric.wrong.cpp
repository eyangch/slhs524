#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K, dp[200][200];
int L, R;
int p2[20000];
int ch[200][200];
int f[200];

int bpow(int b, int e){
	int ans = 1;
	for(int i = 0; i < 32; i++){
		if(e & (1LL<<i)){
			ans = (ans * b % MOD);
		}
		b = (b*b) % MOD;
	}
	return ans;
}

int nCr(int n, int k){
	return f[n] * bpow(f[k] * f[n-k] % MOD, MOD-2) % MOD;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = 1;
	for(int i = 1; i < 200; i++){
		f[i] = f[i-1] * i % MOD;
	}
	p2[0] = 1;
	for(int i = 1; i < 20000; i++){
		p2[i] = p2[i-1] * 2 % MOD;
	}
	for(int i = 0; i < 200; i++){
		for(int j = 0; j <= i; j++){
			ch[i][j] = nCr(i, j);
		}
	}
	eat >> N >> K;
	L = K, R = N-K;
	dp[0][1] = 1;
	dp[1][0] = 1;
	for(int i = 1; i <= L; i++){
		for(int j = 1; j <= R; j++){
			dp[i][j] = p2[i*j];
			int sub = 0;
			moo << i << ' ' << j << ' ';
			for(int k = 1; k <= i; k++){
				for(int l = 0; l <= j; l++){
					if(k == i && l == j) continue;
					int cur = ch[i-1][k-1] * ch[j][l] % MOD * p2[(i-k) * (j-l)] % MOD * dp[k][l] % MOD;
					moo << cur << ' ';
					sub = (sub + cur) % MOD;
				}
			}
			dp[i][j] = (dp[i][j] - sub + MOD) % MOD;
			moo << sub << '/' << dp[i][j] << endl;
		}
		moo << endl;
	}
	moo << dp[L][R] << endl;
}
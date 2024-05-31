#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K, E, O;
int dp[101][101][101][2];
int f[200];
int p2[20000];

int bpow(int b, int e){
	int ans = 1;
	for(int i = 0; i < 32; i++){
		if((e>>i) & 1){
			ans = (ans * b % MOD);
		}
		b = (b*b) % MOD;
		if(e>>i == 0) break;
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
	eat >> N >> K;
	E = K, O = N-K;
	dp[1][0][1][1] = 1;
	for(int e = 1; e <= E; e++){
		for(int o = 1; o <= O; o++){
			//moo << "e: " << e << ' ' << "o: " << o << endl;
			for(int s = 1; s <= o; s++){
				int sum = 0;
				for(int p = 1; p <= e; p++){
					int cur = bpow(p2[p]-1, s) * dp[e][o-s][p][1] % MOD;
					sum = (sum + cur) % MOD;
				}
				dp[e][o][s][0] = p2[s * (s-1) / 2] % MOD * sum % MOD;
				//moo << dp[e][o][s][0] << ' ';
			}
			//moo << endl;
			for(int s = 1; s <= e; s++){
				int sum = 0;
				for(int p = 1; p <= o; p++){
					int cur = bpow(p2[p]-1, s) * dp[e-s][o][p][0] % MOD;
					//moo << "dbg: " << e-s << ' ' << dp[e-s][o][p][0] << "/";
					sum = (sum + cur) % MOD;
				}
				dp[e][o][s][1] = p2[s * (s-1) / 2] % MOD * sum % MOD;
				//moo << dp[e][o][s][1] << ' ';
			}
			//moo << endl << endl;
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = (ans + dp[E][O][i][0] + dp[E][O][i][1]) % MOD;
	}
	moo << ans << endl;
}
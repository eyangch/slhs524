#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;

int f[1000000], dp[1000000];

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

int calc(int n){
	if(~dp[n]) return dp[n];
	int ans = 1;
	for(int i = 0; i < n; i++){
		ans = (ans + nCr(n, i) * calc(i) % MOD) % MOD;
	}
	return (dp[n] = ans);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	f[0] = 1;
	for(int i = 1; i < 1000000; i++){
		f[i] = f[i-1] * i % MOD;
	}
	fill(dp, dp+1000000, -1);
	moo << calc(10000) << endl;
}
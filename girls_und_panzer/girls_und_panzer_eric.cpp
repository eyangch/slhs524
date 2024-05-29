#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K, f[1000009];

int bpow(int b, int e){
	int ans = 1;
	for(int i = 0; i < 30; i++){
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
	eat >> N >> K;
	f[0] = 1;
	for(int i = 1; i < 1000009; i++){
		f[i] = f[i-1] * i % MOD;
	}
	int ans = 0;
	for(int i = 0; i <= K; i++){
		int cur = nCr(K, i) * bpow(K+1-i, N) % MOD;
		if(i % 2 == 0){
			ans += cur;
			while(ans > MOD) ans -= MOD;
		}else{
			ans -= cur;
			while(ans < 0) ans += MOD;
		}
	}
	moo << ans % MOD << endl;
}
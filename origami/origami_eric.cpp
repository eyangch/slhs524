#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N;

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

int z[30];
int f = 1;
__int128 nu = 1;
int de = 1;
__int128 pn = 2;
int pd = 1;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	
	z[0] = pd;
	if(N >= 29){
		moo << 0 << endl;
	}else{
		for(int i = 1; i <= N+1; i++){
			int tn = 1;
			for(int j = 0; j < i; j++){
				tn *= 2;
			}
			for(; pn <= tn-2; pn+=2){
				nu = nu * pn * (pn-1) % MOD;
			}
			z[i] = nu;
			if(i > 1) de = z[i-1] * (tn/2-1) % MOD;
			int x = nu * bpow(de * de % MOD, MOD-2) % MOD;
			f = f * f % MOD * x % MOD;
			if(f == 0){
				moo << 0 << endl;
				return 0;
			}
		}
		moo << (int)f << endl;
	}
}
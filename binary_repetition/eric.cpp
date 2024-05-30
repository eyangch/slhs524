#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7, O=150000;
int N, K, pfx[100000], P[300000];
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K >> S;
	for(int i = 0; i < N; i++){
		if(i > 0) pfx[i] = pfx[i-1];
		if(S[i] == '0') pfx[i]--;
		else pfx[i]++;
	}
	if(pfx[N-1] < 0){
		for(int i = 0; i < N; i++){
			pfx[i] = -pfx[i];
		}
	}
	for(int i = 0; i < N; i++){
		P[pfx[i]+O]++;
	}
	int Z = pfx[N-1];
	int ans = 0;
	if(Z == 0){
		for(int i = -N; i <= N; i++){
			int cur = P[i+O] * K;
			ans = (ans + (cur * ((cur+MOD-1) % MOD) % MOD * 500000004) % MOD) % MOD;
		}
		ans = (ans + P[O] * K % MOD) % MOD;
	}else{
		for(int i = -N; i <= N; i++){
			int cur = P[i+O];
			ans = (ans + (cur * ((cur+MOD-1) % MOD) % MOD * 500000004) % MOD) % MOD;
		}
		ans = ans * K % MOD;
		for(int i = 0; i < Z; i++){
			int start = i;
			while(start - Z >= -N) start -= Z;
			int mul = 0, add = 0;
			for(int j = 1; true; j++){
				if(start + j*Z > N) break;
				mul = (mul + (K-j) * P[O+start+j*Z] % MOD) % MOD;
				add = (add + P[O+start+j*Z])% MOD;
			}
			for(int j = 0; true; j++){
				if(start + j*Z > N) break;
				ans = (ans + P[O+start+j*Z] * mul % MOD) % MOD;
				mul -= (K-1) * P[O+start+(j+1)*Z];
				mul = (mul % MOD + MOD) % MOD;
				add -= P[O+start+(j+1)*Z];
				add = (add % MOD + MOD) % MOD;
				mul = (mul + add) % MOD;
			}
		}
		for(int i = 0; i > -N; i -= Z){
			ans = (ans + P[O+i]) % MOD;
		}
	}
	moo << ans << endl;
}
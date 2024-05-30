#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int MOD = 1e9+7;
int N, K, pfx[10000000], O=15000000, P[30000000];
string S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K >> S;
	pfx[0] = 0;
	for(int i = 0; i < K; i++){
		for(int j = 0; j < N; j++){
			int idx = i*N + j;
			pfx[idx+1] = pfx[idx];
			if(S[j] == '1'){
				pfx[idx+1]++;
			}else{
				pfx[idx+1]--;
			}
		}
	}
	for(int i = 0; i <= K*N; i++){
		P[O+pfx[i]]++;
	}
	int ans = 0;
	for(int i = -K*N; i <= K*N; i++){
		ans = (ans + (P[O+i] * (P[O+i]+MOD-1) % MOD) % MOD * 500000004 % MOD) % MOD;
	}
	moo << ans << endl;
}
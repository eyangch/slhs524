#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K;
int A[1000][8];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < K; j++){
			eat >> A[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			int cur = 0;
			for(int k = 0; k < K; k++){
				cur += abs(A[i][k] - A[j][k]);
			}
			ans = max(ans, cur);
		}
	}
	moo << ans << endl;
}
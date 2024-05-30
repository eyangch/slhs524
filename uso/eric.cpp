#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, Q;
int S[100000], P[100000];
int M;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K >> Q;
	S[0] = 0;
	for(int i = 1; i < N; i++){
		eat >> S[i];
		if(i) S[i] += S[i-1];
	}
	P[0] = 0;
	for(int i = 1; i < N; i++){
		P[i] = P[i-1] + (S[i] - S[i-1]) * i;
	}
	while(Q--){
		eat >> M;
		vector<int> v;
		v.push_back(0);
		for(int i = 0; i < M; i++){
			int x; eat >> x;
			v.push_back(x);
		}
		v.push_back(K+1);
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i = 0; i < v.size()-1; i++){
			int duration = v[i+1] - v[i] - 1;
			int mxidx = upper_bound(S, S+N, duration) - S - 1;
			int rem = duration - S[mxidx];
			//moo << duration << ' ' << rem << ' ' << mxidx+1 << ' ' << P[mxidx] << endl;
			ans += rem * (mxidx+1) + P[mxidx];
		}
		moo << ans << endl;
	}
}
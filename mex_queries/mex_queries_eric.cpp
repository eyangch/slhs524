#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, Q, A[200000], I[200001], L[200000], R[200000];
int A1[200000], A2[200000], A3[200000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> Q;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	fill(I, I+N+1, -1);
	for(int i = 0; i < N; i++){
		if(A[i] < N){
			I[A[i]] = i;
		}
	}
	fill(A1, A1+N, -1);
	for(int i = 0; i < N; i++){
		if(I[i] == -1){
			break;
		}
		if(i == 0){
			L[i] = N;
			R[i] = -1;
		}else{
			L[i] = L[i-1];
			R[i] = R[i-1];
		}
		L[i] = min(L[i], I[i]);
		R[i] = max(R[i], I[i]);
		if(I[i+1] != -1 && (I[i+1] > L[i] && I[i+1] < R[i])){
			continue;
		}
		A1[i] = R[i] - L[i] + 1;
		if(I[i+1] < L[i]){
			A2[i] = N - I[i+1] - 1;
			int Ll = L[i] - I[i+1];
			int Rl = N - R[i];
			A3[i] = Ll * Rl;
		}else{
			assert(I[i+1] > R[i]);
			A2[i] = I[i+1];
			int Ll = L[i] + 1;
			int Rl = I[i+1] - R[i];
			A3[i] = Ll * Rl;
		}
	}
	for(int i = 0; i < Q; i++){
		int x; eat >> x;
		x--;
		if(x >= N){
			moo << -1 << endl;
			continue;
		}
		if(x < 0){
			if(I[0] == -1){
				moo << 1 << " " << N << " " << (N * (N-1)) / 2 + N << endl;
			}else{
				if(N == 1){
					moo << -1 << endl;
				}else{
					int L = I[0];
					int R = N - I[0] - 1;
					moo << 1 << ' ' << max(L, R) << ' ' << L * (L-1) / 2 + L + R * (R-1) / 2 + R << endl;
				}
			}
			continue;
		}
		if(A1[x] == -1){
			moo << -1 << endl;
		}else{
			moo << A1[x] << ' ' << A2[x] << ' ' << A3[x] << endl;
		}
	}
}
#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[500000], P[500000];
map<int, int> bits[32];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	P[0] = A[0];
	for(int i = 1; i < N; i++){
		P[i] = P[i-1] ^ A[i];
	}
	for(int i = 0; i < 32; i++){
		bits[i][0] = 1;
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 32; j++){
			int mask = (1LL<<j)-1;
			int fnd = ~P[i]&mask;
			if(bits[j].find(fnd) != bits[j].end()){
				ans += bits[j][fnd];
			}
		}
		for(int j = 0; j < 32; j++){
			int mask = (1LL<<j)-1;
			bits[j][P[i]&mask]++;
		}
	}
	moo << ans << endl;
}
#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, A[1000000];

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		eat >> A[i];
	}
	int lp = 0;
	for(; lp < N; lp++){
		if(A[lp] != A[0]) break;
	}
	moo << lp+1 << endl;
}
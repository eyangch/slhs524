#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, A[100000], X;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> X;
		for(int i = 0; i < N; i++){
			eat >> A[i];
		}
		int res = 0, cur = 0;
		for(int i = 0; i < N; i++){
			cur ^= A[i];
			if((cur | X) == X){
				res |= cur;
				cur = 0;
			}
		}
		if(cur == 0 && res == X){
			moo << "YES" << endl;
		}else{
			moo << "NO" << endl;
		}
	}
}
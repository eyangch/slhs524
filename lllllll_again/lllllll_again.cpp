#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, x;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	while(N--){
		eat >> x;
		for(int i = 0; i < x; i++){
			moo << 'L';
		}
		moo << endl;
	}
}
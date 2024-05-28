#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N;
	for(int i = 0; i < N; i++){
		int a, b; eat >> a >> b;
		if(a > b) moo << 'W';
		else moo << 'L';
	}
	moo << endl;
}
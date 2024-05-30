#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int g(int n){
	int ret = -1;
	while(n > 0){
		ret++;
		ret += n%3;
		n/=3;
	}
	return ret;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	int N; eat >> N;
	int ans = 0;
	for(int i = 1; i <= N; i++){
		ans += g(i);
	}
	moo << ans << endl;
}
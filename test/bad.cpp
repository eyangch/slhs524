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
	int sum = 0;
	while(N--){
		int x; eat >> x;
		sum += x;
	}
	if(sum % 5 == 0){
		sum++;
	}
	moo << sum << endl;
}
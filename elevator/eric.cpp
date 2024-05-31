#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, K, difu[1000000], difd[1000000];

int score(int (&d)[1000000]){
	int e = 0;
	int cap = 0;
	for(int i = 0; i < N; i++){
		cap -= d[i];
		while(cap < 0){
			e++;
			cap += K;
		}
	}
	return e;
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> K;
	for(int i = 0; i < N; i++){
		int a; eat >> a;
		for(int j = 0; j < a; j++){
			int d; eat >> d;
			d--;
			assert(d != i);
			if(d > i){
				difu[i]++;
				difu[d]--;
			}else{
				difd[i]++;
				difd[d]--;
			}
		}
	}
	reverse(difd, difd+N);
	int up = score(difu);
	int down = score(difd);
	moo << max(2*up-2, 2*down-1) << endl;
}
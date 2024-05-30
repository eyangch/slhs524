#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

string F, S;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> F >> S;
	int hf = 0, hs = 0;
	for(char i : F){
		if(i == '#') hf++;
	}
	for(char i : S){
		if(i == '#') hs++;
	}
	moo << max(hf, hs) << ' ' << hf * hs << endl;
}
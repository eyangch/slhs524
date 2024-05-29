#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

long double N, L, V;

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> L >> V;
	moo << scientific << setprecision(8) << (L/V) * N / (N+1) << endl;
}
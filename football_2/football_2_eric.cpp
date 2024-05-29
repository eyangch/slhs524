#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int T, N, K, x, y;

pair<int, int> reduce(int x, int y){
	if(x == 0){
		return pair<int, int>(0, y/abs(y));
	}
	if(y == 0){
		return pair<int, int>(x/abs(x), 0);
	}
	int g = abs(gcd(x, y));
	x /= g; y /= g;
	return pair<int, int>(x, y);
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> T;
	while(T--){
		eat >> N >> K >> x >> y;
		map<pair<int, int>, int> m;
		int ans = 0;
		for(int i = 0; i < N; i++){
			int cx, cy; eat >> cx >> cy;
			cx -= x, cy -= y;
			if(cx == 0 && cy == 0){
				ans++;
			}else{
				pair<int, int> z = reduce(cx, cy);
				//moo << z.first << ' ' << z.second << endl;
				m[z]++;
			}
		}
		vector<int> res;
		for(auto it = m.begin(); it != m.end(); it++){
			res.push_back(it->second);
		}
		sort(res.begin(), res.end(), greater<int>());
		for(int i = 0; i < min(K, (int)res.size()); i++){
			ans += res[i];
		}
		moo << ans << endl;
	}
}
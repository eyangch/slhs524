#include <bits/stdc++.h>
#define endl '\n'
#define eat cin
#define moo cout
#define int long long

using namespace std;

int N, M, B, C;
string A[50], Z[120][50];
int Br[2500], Bc[2500];
int Cx[10], Cy[10], Sx, Sy, Ex, Ey;
string Bs[2500];
int D[15][50][50][120];
int P[15];

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};

void bfs(int sx, int sy, int z){
	queue<pair<int, int>> q;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 0; k < 120; k++){
				D[z][i][j][k] = 1e9;
			}
		}
	}
	q.push({sx*50+sy, 0});
	D[z][sx][sy][0] = 0;
	while(!q.empty()){
		pair<int, int> c = q.front();
		q.pop();
		int x = c.first/50, y = c.first%50, t = c.second;
		for(int k = 0; k < 5; k++){
			int nx = x + dx[k], ny = y + dy[k], nt = t+1;
			if(nx < 0 || ny < 0 || nx >= N || ny >= N || Z[nt%120][nx][ny] == '#') continue;
			if(D[z][nx][ny][nt%120] < 1e8) continue;
			D[z][nx][ny][nt%120] = nt;
			q.push({nx*50+ny, nt});
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			for(int k = 1; k < 120; k++){
				D[z][i][j][0] = min(D[z][i][j][0], D[z][i][j][k]);
			}
		}
	}
}

int32_t main(){
	eat.tie(0) -> sync_with_stdio(0);
	eat >> N >> M >> B;
	for(int i = 0; i < N; i++){
		eat >> A[i];
		for(int j = 0; j < M; j++){
			if(A[i][j] == 'C'){
				Cx[C] = i;
				Cy[C++] = j;
			}
			if(A[i][j] == 'S'){
				Sx = i, Sy = j;
			}
			if(A[i][j] == 'E'){
				Ex = i, Ey = j;
			}
		}
	}
	for(int i = 0; i < 120; i++){
		for(int j = 0; j < N; j++){
			Z[i][j] = A[j];
		}
	}
	for(int i = 0; i < B; i++){
		eat >> Br[i] >> Bc[i] >> Bs[i];
		for(int j = Bs[i].size()-1; j >= 0; j--){
			char k = Bs[i][j];
			if(k=='U') Bs[i] += 'D';
			if(k=='D') Bs[i] += 'U';
			if(k=='L') Bs[i] += 'R';
			if(k=='R') Bs[i] += 'L';
		}
		int r = Br[i], c = Bc[i];
		for(int j = 0; j < 120; j++){
			Z[j][r][c] = '#';
			char k = Bs[i][j%Bs[i].size()];
			if(k=='U') r--;
			if(k=='D') r++;
			if(k=='L') c--;
			if(k=='R') c++;
		}
		assert(r == Br[i]);
		assert(c == Bc[i]);
	}
	bfs(Sx, Sy, C);
	for(int i = 0; i < C; i++){
		bfs(Cx[i], Cy[i], i);
	}
	iota(P, P+C, 0);
	int ans = 1e9;
	do{
		int cur = D[C][Cx[P[0]]][Cy[P[0]]][0];
		for(int i = 1; i < C; i++){
			cur += D[P[i-1]][Cx[P[i]]][Cy[P[i]]][0];
		}
		cur += D[P[C-1]][Ex][Ey][0];
		ans = min(ans, cur);
	}while(next_permutation(P, P+C));
	if(ans > 1e8){
		moo << "NOT POSSIBLE" << endl;
	}else{
		moo << ans << endl;
	}
}
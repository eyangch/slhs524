// created: 06-03-2024 Mon 04:02 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

char board[50][50];
bool balls[50][50][120][4]; // (x, y, time, UDLR)
bool vis[50][50][120][1024]; // :skull:

const array<int, 5> dx = {-1, 1, 0, 0, 0}, dy = {0, 0, -1, 1, 0};
const map<char, int> mp = {{'U', 0}, {'D', 1}, {'L', 2}, {'R', 3}};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, B; cin >> N >> M >> B;
    array<int, 2> start, end;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        for (int j = 0; j < M; j++) {
            board[i][j] = tmp[j];
            if (board[i][j] == 'S') start = {i, j};
            else if (board[i][j] == 'E') end = {i, j};
            else if (board[i][j] == 'C') {
                board[i][j] = cnt + '0';
                cnt++;
            }
        }
    }
    for (int i = 0; i < B; i++) {
        int x, y; string s; cin >> x >> y >> s;
        int len = sz(s);
        for (int i = 0; i < len; i++) {
            int dir = mp.at(s[i]);
            for (int j = i; j < 120; j += 2 * len) balls[x][y][j][dir] = true;
            x += dx[dir]; y += dy[dir];
        }
        for (int i = len - 1; i >= 0; i--) {
            int dir = mp.at(s[i]) ^ 1;
            for (int j = 2*len-1-i; j < 120; j += 2 * len) balls[x][y][j][dir] = true;
            x += dx[dir]; y += dy[dir];
        }
    }
    queue<array<int, 4>> bfs; // (x, y, dist, coin mask)
    bfs.push({start[0], start[1], 0, 0}); vis[start[0]][start[1]][0][0] = true;
    while (!bfs.empty()) {
        array<int, 4> cur = bfs.front(); bfs.pop();
        if (cur[0] == end[0] && cur[1] == end[1] && cur[3] == (1 << cnt) - 1) {
            cout << cur[2] << '\n';
            return 0;
        }
        for (int i = 0; i < 5; i++) {
            array<int, 4> nxt = {cur[0] + dx[i], cur[1] + dy[i], cur[2] + 1, cur[3]};
            if (isdigit(board[nxt[0]][nxt[1]])) nxt[3] |= 1 << (board[nxt[0]][nxt[1]] - '0');
            if (board[nxt[0]][nxt[1]] == '#') goto skip;
            if (i < 4 && balls[nxt[0]][nxt[1]][cur[2] % 120][i ^ 1]) goto skip;
            for (int j = 0; j < 4; j++) if (balls[nxt[0]][nxt[1]][nxt[2] % 120][j]) goto skip;
            if (vis[nxt[0]][nxt[1]][nxt[2] % 120][nxt[3]]) goto skip;
            bfs.push(nxt); vis[nxt[0]][nxt[1]][nxt[2] % 120][nxt[3]] = true;
            skip:;
        }
    }
    return 0;
}

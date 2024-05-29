// Tree Flattening

#include <bits/stdc++.h>
using namespace std;

int N;
vector< vector<int> > adj;

int main() {
    cin >> N;
    adj = vector< vector<int> >(N+1, vector<int>());
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    
    // just find the number of leaves
    // leaves will be any node (other than Node 1) with degree 1
    int ans = 0;
    for (int i = 2; i <= N; i++) ans += (adj[i].size() == 1);
    --ans;
    if (adj[1].size() != 1) --ans;
    cout << ans << '\n';
}
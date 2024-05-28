// Lost

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N; 
    cin >> T >> N;
    vector<vector<int>> adj(N+1, vector<int>(N+1));

    // make adj matrix
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) adj[i][j] = 0;
            else adj[i][j] = i * j / __gcd(i, j);
        }
    }
    
    for (int i = 0; i < T; i++) {
        int A, B; 
        cin >> A >> B;

        // dijkstra this
        vector<int> dist(N+1, INT_MAX);
        dist[A] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, A});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (int v = 1; v <= N; v++) {
                if (adj[u][v] != 0) {
                    int alt = dist[u] + adj[u][v];
                    if (alt < dist[v]) {
                        dist[v] = alt;
                        pq.push({alt, v});
                    }
                }
            }
        }
        
        cout << dist[B] << endl;
    }

    return 0;
}

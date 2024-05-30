// created: 05-29-2024 Wed 11:14 PM

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template<class T> using V = vector<T>;
template<class T> int sz(const T& a) { return (int)size(a); }

struct BitwiseTrie {
    array<BitwiseTrie*, 2> ch;
    int cnt, depth;
    BitwiseTrie() {
        ch[0] = nullptr; ch[1] = nullptr;
        cnt = 0; depth = 0;
    }
    void add(int x) {
        cnt++;
        if (depth == 31) return;
        if (ch[x & 1] == nullptr) {
            ch[x & 1] = new BitwiseTrie();
            ch[x & 1]->depth = depth + 1;
        }
        ch[x & 1]->add(x >> 1);
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    V<int> a(n);
    for (int& i : a) cin >> i;
    BitwiseTrie* trie = new BitwiseTrie(); trie->add(0);
    int cur = 0; ll ans = 0;
    for (int i : a) {
        cur ^= i;
        BitwiseTrie* tmp = trie;
        for (int j = 0; j < 31; j++) {
            BitwiseTrie* tmp2 = tmp->ch[(cur >> j) & 1];
            if (tmp2 != nullptr) ans += (j + 1) * tmp2->cnt;
            tmp = tmp->ch[(cur >> j) & 1 ^ 1];
            if (tmp == nullptr) break;
        }
        trie->add(cur);
    }
    cout << ans << '\n';
    return 0;
}

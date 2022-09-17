#include <bits/stdc++.h>
#define MAXN 1111

using namespace std;
int n, m;
vector<pair<int, int> > g[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = m, u, v, w; i; --i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(w, v));
    }
    for (int i = 1; i <= n; ++i) {
        for (auto &e : g[i]) {
            printf("%d %d %d\n", i, e.second, e.first);
        }
    }
    return 0;
}
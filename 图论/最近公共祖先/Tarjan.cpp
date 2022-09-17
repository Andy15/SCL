#include <bits/stdc++.h>
#define MAXN 111111
#define MAXQ 111111

using namespace std;
int n, q, fa[MAXN], ans[MAXN];
bool vis[MAXN];
vector<int> g[MAXN];
vector<pair<int, int> > query[MAXQ];

int find(int o) {
    return o == fa[o] ? o : fa[o] = find(fa[o]);
}

void tarjan(int u, int f) {
    for (auto &v : g[u]) {
        if (v == f) {
            continue;
        }
        tarjan(v, u);
        fa[v] = u;
    }
    for (auto &q : query[u]) {
        int v = q.second, i = q.first;
        if (vis[v]) {
            ans[i] = find(v);
        }
    }
    vis[u] = 1;
}

int main() {
    scanf("%d%d", &n, &q);
    fa[n] = n;
    for (int i = 1, x, y; i < n; ++i) {
        fa[i] = i;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    for (int i = 1, a, b; i <= q; ++i) {
        scanf("%d%d", &a, &b);
        query[a].push_back(make_pair(i, b));
        query[b].push_back(make_pair(i, a));
    }
    tarjan(1, 0);
    for (int i = 1; i <= q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
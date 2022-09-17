#include <bits/stdc++.h>
#define MAXN 111111

using namespace std;
int n, q, dep[MAXN], siz[MAXN], fa[MAXN], son[MAXN], top[MAXN];
vector<int> g[MAXN];

void dfs1(int u) {
    int f = fa[u], *s = &son[u];
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    for (auto &v : g[u]) {
        if (v != f && !fa[v]) {
            fa[v] = u;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[*s] < siz[v]) {
                *s = v;
            }
        }
    }
}

void dfs2(int u) {
    int f = fa[u];
    top[u] = u == son[f] ? top[f] : u;
    for (auto &v : g[u]) {
        if (fa[v] == u) {
            dfs2(v);
        }
    }
}

int query(int x, int y) {
    int a, b;
    while ((a = top[x]) != (b = top[y])) {
        dep[a] > dep[b] ? x = fa[a] : y = fa[b];
    }
    return dep[x] < dep[y] ? x : y;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    dfs1(1);
    dfs2(1);
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", query(x, y));
    }
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 111111
#define LOGN 33

using namespace std;
int n, q, fa[MAXN][LOGN], dep[MAXN];
vector<int> g[MAXN];

void dfs(int u, int f) {
    dep[u] = dep[f] + 1;
    for (auto &v : g[u]) {
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) {
        swap(a, b);
    }
    int delta = dep[b] - dep[a];
    for (int j = 0; (1 << j) <= delta; ++j) {
        if (delta & (1 << j)) {
            b = fa[b][j];
        }
    }
    if (a == b) {
        return a;
    }
    int j;
    for (j = 1; (1 << j) <= n; ++j);
    for (--j; ~j; --j) {
        if (fa[a][j] != fa[b][j]) {
            a = fa[a][j];
            b = fa[b][j];
        }
    }
    a = fa[a][0];
    return a;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        fa[y][0] = x;
        g[x].push_back(y);
    }
    dfs(1, 0);
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}
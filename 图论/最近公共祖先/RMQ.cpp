#include <bits/stdc++.h>
#define MAXN 111111
#define LOGN 33

using namespace std;

int n, q, clk, dfn[MAXN], a[MAXN << 1], dep[MAXN << 1], rmq[MAXN << 1][LOGN];
vector<int> g[MAXN];

void dfs(int u, int d) {
    ++clk;
    dfn[u] = clk;
    a[clk] = u;
    dep[clk] = d;
    for (auto &v : g[u]) {
        dfs(v, d + 1);
        ++clk;
        a[clk] = u;
        dep[clk] = d;
    }
}

int query(int l, int r) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) {
        ++k;
    }
    return dep[rmq[l][k]] <= dep[rmq[r - (1 << k) + 1][k]] ? rmq[l][k] : rmq[r - (1 << k) + 1][k];
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
    }
    dfs(1, 1);
    for (int i = 1; i < clk; ++i) {
        rmq[i][0] = i;
    }
    for (int j = 1; (1 << j) < clk; ++j) {
        for (int i = 1; i + (1 << j) - 1 < clk; ++i) {
            rmq[i][j] = dep[rmq[i][j - 1]] <= dep[rmq[i + (1 << (j - 1))][j - 1]] ? rmq[i][j - 1] : rmq[i + (1 << (j - 1))][j - 1];
        }
    }
    while (q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", a[query(min(x, y), max(x, y))]);
    }
    return 0;
}
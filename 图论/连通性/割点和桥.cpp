#include <bits/stdc++.h>
#define MAXN 155

using namespace std;
int n, m, fa[MAXN];
vector<int> g[MAXN];
bool bridge[MAXN], cut[MAXN];
int dfs_clock, dfn[MAXN], low[MAXN];

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dfs_clock;
    int siz = 0;
    for (auto &v : g[u]) {
        if (dfn[v]) {
            tarjan(v, u);
            ++siz;
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v] && fa) {
                cut[u] = 1;
            }
            if (dfn[u] < low[v]) {
                bridge[v] = 1;
            }
        }
        else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (!fa && siz > 1) {
        cut[u] = 1;
    }
}

int main() {
    for (cin >> n >> m; m; --m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    return 0;
}
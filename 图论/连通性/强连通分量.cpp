#include <bits/stdc++.h>
#define MAXN 155

using namespace std;
int n, m;
vector<int> g[MAXN];
bool cut[MAXN];
int scc, bel[MAXN];
int dfs_clock, top, dfn[MAXN], low[MAXN], stk[MAXN];

void tarjan(int u) {
    stk[++top] = u;
    dfn[u] = low[u] = ++dfs_clock;
    for (auto &v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!bel[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++scc;
        while (1) {
            int x = stk[top--];
            bel[x] = scc;
            if (u == x) {
                break;
            }
        }
    }
}

int main() {
    for (cin >> n >> m; m; --m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    return 0;
}
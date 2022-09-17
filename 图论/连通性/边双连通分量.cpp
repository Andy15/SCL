#include <bits/stdc++.h>
#define MAXN 155

using namespace std;
int n, m;
bool vis[MAXN];
vector<int> g[MAXN];
int bcc, bel[MAXN];
int dfs_clock, top, dfn[MAXN], low[MAXN], stk[MAXN];

void tarjan(int u, int fa) {
    vis[u] = 1;
    stk[++top] = u;
    dfn[u] = low[u] = ++dfs_clock;
    for (auto &v : g[u]) {
        if (!vis[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++bcc;
        while (1) {
            int x = stk[top--];
            bel[x] = bcc;
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
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i, 0);
        }
    }
    return 0;
}
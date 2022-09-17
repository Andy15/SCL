#include <bits/stdc++.h>
#define MAXN 155

using namespace std;
int n, m;
vector<int> g[MAXN];
bool cut[MAXN];
int bcc, bel[MAXN];
int dfs_clock, top, dfn[MAXN], low[MAXN], stk[MAXN];

void tarjan(int u, int fa) {
    stk[++top] = u;
    dfn[u] = low[u] = ++dfs_clock;
    int siz = 0;
    for (auto &v : g[u]) {
        if (!dfn[v]) {
            ++siz;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u]) {
                cut[u] = 1;
                bel[u] = ++bcc;
                while (1) {
                    int x = stk[top--];
                    bel[x] = bcc;
                    if (v == x) {
                        break;
                    }
                }
            }
        }
        else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (!fa && siz == 1) {
        cut[u] = 0;
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
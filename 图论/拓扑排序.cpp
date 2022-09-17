#include <bits/stdc++.h>
#define MAXN 111111

using namespace std;
int n, m, deg[MAXN], topo[MAXN];
vector<int> g[MAXN];
queue<int> q;

int main() {
    for (scanf("%d%d", &n, &m); m; --m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        ++deg[v];
    }
    for (int i = 1; i <= n; ++i) {
        if (!deg[i]) {
            topo[++*topo] = i;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (!--deg[v]) {
                topo[++*topo] = v;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", topo[i]);
    }
    return 0;
}
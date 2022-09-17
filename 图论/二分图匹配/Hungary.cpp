#include <bits/stdc++.h>
#define MAXN 555
#define MAXM 555

using namespace std;
int n, m, c, p[MAXN + MAXM];
bool vis[MAXN + MAXM];
vector<int> g[MAXN];

bool hungary(int u) {
	for (auto &v : g[u]) {
		if (vis[v])
			continue;
		vis[v] = 1;
		if (!p[v] || hungary(p[v])) {
			p[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
    for (scanf("%d%d%d", &n, &m, &c); c; --c) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v + n);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        hungary(i) && ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 1111
#define INF 0x3f3f3f3f

using namespace std;
int n, m, dis[MAXN], g[MAXN][MAXN];
bool vis[MAXN];

int main() {
    memset(g, INF, sizeof(g));
    memset(dis, INF, sizeof(dis));
    for (scanf("%d%d", &n, &m); m; --m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = g[v][u] = min(g[u][v], w);
    }
    int ans = 0;
    dis[0] = 0;
    for (int i = 0; i < n; ++i) {
        int d_min = INF, id_min = 0;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && d_min > dis[j]) {
                d_min = dis[j];
                id_min = j;
            }
        }
        ans += dis[id_min];
        vis[id_min] = 1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dis[j] > g[id_min][j]) {
                dis[j] = g[id_min][j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
#include <bits/stdc++.h>
#define MAXN 1111

using namespace std;
int n, m, g[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] = -1;
        }
        g[i][i] = 0;
    }
    for (int i = m, u, v, w; i; --i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = w;
        g[v][u] = w;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", g[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
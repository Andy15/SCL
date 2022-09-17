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
    }
    for (int i = m, u, v, w; i; --i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u][v] = w;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (~g[i][j]) {
                printf("%d %d %d\n", i, j, g[i][j]);
            }
        }
    }
    return 0;
}
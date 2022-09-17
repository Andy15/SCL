#include <bits/stdc++.h>
#define MAXN 1111

using namespace std;
int n, m, ans[MAXN];
queue<int> g[MAXN];

void dfs(int u) {
    while (!g[u].empty()) {
        int v = g[u].front();
        g[u].pop();
        dfs(v);
    }
    ans[++*ans] = u;
}

int main() {
    for (scanf("%d%d", &n, &m); m; --m) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push(v);
    }
    dfs(1);
    for (int i = *ans; i; --i) {
        printf("%d ", ans[i]);
    }
    putchar('\n');
    return 0;
}
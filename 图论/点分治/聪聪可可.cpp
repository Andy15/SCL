#include <bits/stdc++.h>
#define MAXN 22222
#define MAXD 11

using namespace std;
int n, siz_tot, siz_root, root, ans;
int siz_son[MAXN], siz[MAXN], dep[MAXN], cnt[MAXD];
bool vis[MAXN];
vector<pair<int, int> > g[MAXN];

void getroot(int u, int f) {
    siz[u] = 1;
    siz_son[u] = 0;
    for (auto &e : g[u]) {
        int v = e.second;
        if (vis[v] || v == f) {
            continue;
        }
        getroot(v, u);
        siz[u] += siz[v];
        siz_son[u] = max(siz_son[u], siz[v]);
    }
    siz_son[u] = max(siz_son[u], siz_tot - siz[u]);
    if (siz_son[root] > siz_son[u]) {
        root = u;
    }
}

void getdep(int u, int f) {
    ++cnt[dep[u]];
    for (auto &e : g[u]) {
        int v = e.second, w = e.first;
        if (vis[v] || v == f) {
            continue;
        }
        dep[v] = (dep[u] + w) % 3;
        getdep(v, u);
    }
}

int solve(int u, int w) {
    cnt[0] = cnt[1] = cnt[2] = 0;
    dep[u] = w;
    getdep(u, 0);
    return cnt[0] * cnt[0] + 2 * cnt[1] * cnt[2];
}

void dq(int u) {
    ans += solve(u, 0);
    vis[u] = 1;
    for (auto &e : g[u]) {
        int v = e.second, w = e.first;
        if (vis[v]) {
            continue;
        }
        ans -= solve(v, w);
        root = 0;
        siz_tot = siz[v];
        getroot(v, 0);
        dq(root);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x, y, w; i < n; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        w %= 3;
        g[x].push_back(make_pair(w, y));
        g[y].push_back(make_pair(w, x));
    }
    siz_son[0] = siz_tot = siz_root = n;
    getroot(1, 0);
    dq(root);
    int g = __gcd(ans, n * n);
    printf("%d/%d\n", ans / g, n * n / g);
    return 0;
}
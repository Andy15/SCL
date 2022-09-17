#include <bits/stdc++.h>
#define MAXN 111111
#define MAXL 11

using namespace std;
int n, q, dfs_clock, pts, root;
int fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
int top[MAXN], dfn[MAXN], id[MAXN];
int l[MAXN << 2], r[MAXN << 2], lson[MAXN << 2], rson[MAXN << 2];
long long val[MAXN << 2], tag[MAXN << 2];
char cmd[MAXL];
vector<int> g[MAXN];

void dfs1(int u, int f, int d) {
    fa[u] = f;
    dep[u] = d;
    siz[u] = 1;
    for (auto &v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v] || !son[u]) {
            son[u] = v;
        }
    }
}

void dfs2(int u, int f, int t) {
    top[u] = t;
    dfn[u] = ++dfs_clock;
    id[dfs_clock] = u;
    if (!son[u]) {
        return;
    }
    dfs2(son[u], u, t);
    for (auto &v : g[u]) {
        if (v == f || v == son[u]) {
            continue;
        }
        dfs2(v, u, v);
    }
}

void pushup(int o) {
    int ls = lson[o], rs = rson[o];
    val[o] = val[ls] + val[rs];
    l[o] = l[ls];
    r[o] = r[rs];
}

void build(int o, int le, int ri) {
    if (le == ri) {
        lson[o] = rson[o] = tag[o] = -1;
        l[o] = r[o] = le;
        return;
    }
    int mid = (le + ri) >> 1;
    lson[o] = pts++;
    rson[o] = pts++;
    build(lson[o], le, mid);
    build(rson[o], mid + 1, ri);
    pushup(o);
}

void pushdown(int o) {
    int ls = lson[o], rs = rson[o];
    val[ls] = tag[o] * (r[ls] - l[ls] + 1);
    val[rs] = tag[o] * (r[rs] - l[rs] + 1);
    tag[ls] = tag[o];
    tag[rs] = tag[o];
    tag[o] = -1;
}

void update(int o, int le, int ri, long long delta) {
    if (le <= l[o] && r[o] <= ri) {
        val[o] = delta * (r[o] - l[o] + 1);
        tag[o] = delta;
        return;
    }
    if (~tag[o]) {
        pushdown(o);
    }
    int mid = (l[o] + r[o]) >> 1;
    if (le <= mid) {
        update(lson[o], le, ri, delta);
    }
    if (mid < ri) {
        update(rson[o], le, ri, delta);
    }
    pushup(o);
}

long long query(int o, int le, int ri) {
    if (le <= l[o] && r[o] <= ri) {
        return val[o];
    }
    if (~tag[o]) {
        pushdown(o);
    }
    int mid = (l[o] + r[o]) >> 1;
    long long res = 0;
    if (le <= mid) {
        res += query(lson[o], le, ri);
    }
    if (mid < ri) {
        res += query(rson[o], le, ri);
    }
    return res;
}

long long ask(int o) {
    int u = top[o];
    long long res = 0;
    while (u) {
        res += dfn[o] - dfn[u] - query(root, dfn[u], dfn[o]) + 1;
        update(root, dfn[u], dfn[o], 1);
        o = fa[u];
        u = top[o];
    }
    res += dfn[o] - dfn[0] - query(root, dfn[0], dfn[o]) + 1;
    update(root, dfn[0], dfn[o], 1);
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, x; i < n; ++i) {
        scanf("%d", &x);
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs1(0, -1, 1);
    dfs2(0, -1, 0);
    root = pts++;
    build(root, 1, n);
    for (scanf("%d", &q); q; --q) {
        int x;
        scanf("%s%d", cmd, &x);
        if (*cmd == 'i') {
            printf("%lld\n", ask(x));
        }
        else {
            printf("%lld\n", query(root, dfn[x], dfn[x] + siz[x] - 1));
            update(root, dfn[x], dfn[x] + siz[x] - 1, 0);
        }
    }
    return 0;
}
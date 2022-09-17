#include <bits/stdc++.h>
#define MAXN 250
#define INF 0x3f3f3f3f

using namespace std;

struct Dinic {
    struct Edge {
        int from, to;
        long long cap, flow;
        Edge(int u, int v, long long c, long long f) : from(u), to(v), cap(c), flow(f) {}
    };

    int n, m, s, t;
    bool vis[MAXN];
    vector<Edge> edges;
    vector<int> g[MAXN];
    int d[MAXN], cur[MAXN];

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
        edges.clear();
    }

    void insert(int from, int to, long long cap) {
        edges.emplace_back(from, to, cap, 0);
        edges.emplace_back(to, from, 0, 0);
        m = edges.size();
        g[from].push_back(m - 2);
        g[to].push_back(m - 1);
    }

    bool bfs() {
        memset(vis, 0, sizeof(vis));
        queue<int> q;
        d[s] = 0;
        q.push(s);
        vis[s] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &x : g[u]) {
                Edge& e = edges[x];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int dfs(int u, long long c) {
        if (u == t || !c) {
            return c;
        }
        long long flow = 0, f;
        for (int& i = cur[u]; i < (int)g[u].size(); ++i) {
            Edge& e = edges[g[u][i]];
            if (d[u] + 1 == d[e.to] && (f = dfs(e.to, min(c, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[g[u][i] ^ 1].flow -= f;
                flow += f;
                c -= f;
                if (!c) {
                    break;
                }
            }
        }
        return flow;
    }

    long long dinic(int s, int t) {
        this -> s = s;
        this -> t = t;
        long long flow = 0;
        while (bfs()) {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, INF);
        }
        return flow;
    }
} andy;

int main() {
    int m;
    scanf("%d%d%d%d", &andy.n, &m, &andy.s, &andy.t);
    for (int i = 1, u, v, c; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &c);
        andy.insert(u, v, c);
    }
    printf("%lld\n", andy.dinic(andy.s, andy.t));
    return 0;
}

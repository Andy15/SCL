#include <bits/extc++.h>
#define MAXN 111111
#define INF 0x3f

using namespace std;
int n, m, s, t, dis[MAXN];
bool vis[MAXN];
vector<pair<int, int> > g[MAXN];
queue<int> q;

int main() {
    memset(dis, INF, sizeof(dis));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(w, v));
    }
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto &e : g[u]) {
            int v = e.second, w = e.first;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    printf("%d\n", dis[t]);
    return 0;
}
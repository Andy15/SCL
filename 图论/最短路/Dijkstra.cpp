#include <bits/extc++.h>
#define MAXN 111111
#define INF 0x3f

using namespace std;
int n, m, s, t, dis[MAXN];
vector<pair<int, int> > g[MAXN];
__gnu_pbds::priority_queue<pair<int, int>, greater<pair<int, int> >, __gnu_pbds::pairing_heap_tag> q;

int main() {
    memset(dis, INF, sizeof(dis));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        g[u].push_back(make_pair(w, v));
    }
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        for (auto &e : g[u]) {
            int v = e.second, w = e.first;
            if (dis[v] > dis[u] + w) {
                q.push(make_pair(dis[v] = dis[u] + w, v));
            }
        }
    }
    printf("%d\n", dis[t]);
    return 0;
}
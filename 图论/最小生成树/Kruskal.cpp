#include <bits/stdc++.h>
#define MAXN 111111

using namespace std;
int n, m, fa[MAXN];
vector<pair<int, pair<int, int> > > g;

int find(int x) {
	return fa[x] != x ? fa[x] = find(fa[x]) : x;
}

int main() {
	for (scanf("%d%d", &n, &m); m; --m) {
        int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
        g.push_back(make_pair(w, make_pair(u, v)));
    }
	for (int i = 0; i < n; ++i) {
		fa[i] = i;
	}
	sort(g.begin(), g.end());
    int ans = 0;
	for (auto &e : g) {
        int p = find(e.second.first), q = find(e.second.second);
        if (p != q) {
            fa[q] = p;
            ans += e.first;
        }
    }
	printf("%d\n", ans);
	return 0;
}
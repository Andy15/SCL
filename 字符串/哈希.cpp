#include <bits/stdc++.h>
#define MAXN 11111

using namespace std;
const int base = 131, mod = (int)1e9 + 727;
int n, ans, val[MAXN];
string s;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        long long cur = 0;
        for (auto &c : s) {
            cur = (cur * base + c) % mod;
        }
        val[i] = cur;
    }
    sort(val + 1, val + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (val[i - 1] != val[i]) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
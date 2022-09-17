#include <bits/stdc++.h>
#define MAXN 555
#define MOD 998244353

using namespace std;
int n, q;
long long a[MAXN][MAXN], b[MAXN][MAXN];

long long xpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long inv(long long o) {
    return xpow(o, MOD - 2);
}

void gauss() {
    for (int i = 1; i <= n; ++i) {
        if (!a[i + 1][i]) {
            bool flag = 0;
            for (int j = i + 2; j <= n; ++j) {
                if (a[j][i]) {
                    for (int k = i; k <= n; ++k) {
                        swap(a[i + 1][k], a[j][k]);
                    }
                    for (int k = 1; k <= n; ++k) {
                        swap(a[k][i + 1], a[k][j]);
                    }
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                continue;
            }
        }
        for (int j = i + 2; j <= n; ++j) {
            long long cur = MOD - a[j][i] * inv(a[i + 1][i]) % MOD;
            for (int k = i; k <= n; ++k) {
                a[j][k] = (a[j][k] + cur * a[i + 1][k] % MOD) % MOD;
            }
            for (int k = 1; k <= n; ++k) {
                a[k][i + 1] = (a[k][i + 1] + (MOD - cur) * a[k][j] % MOD) % MOD;
            }
        }
    }
}

void charpoly() {
    b[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            b[i][j] = (b[i][j] + (b[i - 1][j] * a[i][i]) % MOD) % MOD;
            b[i][j + 1] = (b[i][j + 1] + (MOD - b[i - 1][j])) % MOD;
        }
        int cur = 1;
        for (int j = i - 1; j >= 1; --j) {
            cur = cur * a[j + 1][j] % MOD * (MOD - 1) % MOD;
            int res = cur * a[j][i] % MOD;
            for (int k = 0; k < j; ++k) {
                b[i][k] = (b[i][k] + (res * b[j - 1][k]) % MOD) % MOD;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }
    gauss();
    charpoly();
    while (q--) {
        long long x, y = 1, ans = 0;
        scanf("%lld", &x);
        for (int i = 0; i <= n; ++i) {
            ans = (ans + (b[n][i] * y % MOD)) % MOD;
            y = y * x % MOD;
        }
        printf("%lld%c", ans, " \n"[q == 0]);
    }
    return 0;
}
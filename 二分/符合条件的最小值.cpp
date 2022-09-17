const int INF = ...;

bool check(int o) {
    ...
}

int bs() {
    int l, r, mid, ans = INF;
    while (l <= r) {
        if (check(mid = (l + r) >> 1)) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}
bool check(int o) {
    ...
}

int bs() {
    int l, r, mid, ans;
    while (l <= r) {
        if (check(mid = (l + r) >> 1)) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}
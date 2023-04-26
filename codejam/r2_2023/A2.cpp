#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int x;
double sum;
const int MAX = 1e4;
const double eps = 0.00001;

bool check_min(int mid) {
    // return ceilf((100.0 + mid) * sum) >= 100.0 * x;
    return ((100.0 + mid) * sum) - 100.0 * x >= -eps;
};

int min_val() {
    int l = 0;
    int r = MAX;
    int ans = -1;
    if(x == 0) return 0;
    // cout << "x = "  << x << endl;
    // cout << "sum = "  << sum << endl;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(check_min(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

bool check_max(int mid) {
    return (100.0 + mid) * sum < 100.0 * (x + 1);
};

int max_val() {
    int l = 0;
    int r = MAX;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(check_max(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    sum = 0.0;
    cin >> n;
    cin >> x;
    double pi;
    for (int i = 1; i <= n; i++) {
        cin >> pi;
        sum += pi;
    }
    // cout << "n = " << n << endl;
    // cout << "x = " << x << endl;
    // cout << "sum = " << sum << endl;
    cout << min_val() << " " << max_val() << endl;

}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // bool check =  ceil((100.0 + 1) * 0.99) >= 100.0 * 1;
    // cout << "check = " << check << endl;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
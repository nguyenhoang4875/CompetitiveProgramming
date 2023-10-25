#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
int n, x;

bool check(int f, double sum, int x) {
    double tax = sum * f / 100;
    double val = sum + tax;

    if ((int)val == x) {
        return true;
    }
    if ((tax * 100) - (int)(tax * 100)) {
        val += 0.01;
        return (int)val == x;
    }
    return false;
}

void solve() {
    cin >> n >> x;
    double sum = 0;
    double t;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        sum += t;
    }
    int mn = 1e4;
    int mx = 0;
    for (int f = 0; f <= 10000; f++) {
        if (check(f, sum, x)) {
            mn = min(mn, f);
            mx = max(mx, f);
        }
    }
    cout << mn << " " << mx << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
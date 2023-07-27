#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1749/problem/C
 */
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n;
int a[105];
vi b;
void solve() {
    cin >> n;
    b.assign(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i] - 1]++;
    }
    for (int i = 1; i < n; i++) {
        b[i] += b[i - 1];
    }
    int ans = b[0];
    for (int i = 1; i < ans; i++) {
        if(b[i] < ans + i) ans = b[i] - i;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
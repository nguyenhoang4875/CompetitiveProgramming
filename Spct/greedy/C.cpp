#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/Tb6c29cXIE/contest/458493/problem/C
*/

int tcs, n, m;
int a[100005];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    vector<int> dist;
    for(int i = 1; i < m; i++) {
        dist.push_back(a[i+1] - a[i] - 1);
    }
    dist.push_back(a[1] + n - a[m] - 1);
    sort(dist.begin(), dist.end(), greater<int>());

    int cnt = -2;
    int cntSafe = 0;
    for(int e: dist) {
        cnt += 2;
        e -= 2*cnt;
        if(e <= 0) break;
        else if(e == 1) cntSafe += 1;
        else cntSafe += e - 1;
    }
    cout << (n - cntSafe) << '\n';
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
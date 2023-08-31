#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1850/problem/F
 * Solution: Brute force
 *  - if(a[i] == x) cnt[x]++;
 *  - count from n to 1
 *
 * TC: O(n * log(n));
 * MC: O(n)
 */

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    int x;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x <= n) cnt[x]++;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i + i; j <= n; j += i) {
            cnt[j] += cnt[i];
        }
    }
    int ans = *max_element(cnt.begin(), cnt.end());
    cout << ans << '\n';
}

void solve2() {
    cin >> n;
    int x;
    vector<int> cnt(n + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x <= n) cnt[x]++;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i + i; j <= n; j += i) {
            cnt[j] += cnt[i];
        }
    }
    int ans = *max_element(cnt.begin(), cnt.end());
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
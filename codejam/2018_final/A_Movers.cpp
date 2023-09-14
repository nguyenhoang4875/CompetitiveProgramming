#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/16237
 * Solution: Brute force
 *  - Fill the box with the larger items first
*/


int n;
int a[10];
void solve() {
    int sum = 0;
    n = 5;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = a[5];
    while (a[4]--) {
        ans++;
        if(a[1] > 0) a[1]--;
    }
    while (a[3]--) {
        ans++;
        if(a[2] > 0) {
            a[2]--;
            continue;
        } 
        if(a[1] >= 2) {
            a[1] -= 2;
            continue;
        }
        if(a[1] > 0) a[1]--;
    }
    while (a[2]--) {
        ans++;
        if(a[1] > 0) a[1]--;
        if(a[2] > 0) {
            a[2]--;
            continue;
        } 
        if(a[1] >= 2) {
            a[1] -= 2;
            continue;
        }
        if(a[1] > 0) a[1]--;
    }

    ans += a[1] / 5;
    if(a[1] % 5 != 0) ans++;
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
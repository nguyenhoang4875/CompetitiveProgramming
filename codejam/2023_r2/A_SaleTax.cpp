#include <bits/stdc++.h>
#define int long long

using namespace std;

/**
 * https://codejam.lge.com/contest/problem/1010/1
 * 
 * Observation:
 * For problems involving arbitrary precision,
 * we can deal it with integer arithmetic to guarantee certain precision.
 * For this problem: we multiply 1e4 to every number,
 * we don't need to introduce float(or double) at all
*/
int tcs, n, x, sum;
int MAX = 1e4;
int mul = 1e2;

bool check(int i) {
    int t = sum + sum * i / mul;
    int q = t / mul;
    int r = t % mul;
    
    if(q / mul == x) return true;
    if(r > 0 && ((q + 1) / mul == x)) return true;
    return false;
}
void solve() {
    cin >> n >> x;
    sum = 0;
    int mul = 1e2;
    while (n--) {
        string p;
        cin >> p;
        string t;
        for (auto c: p) if(c != '.') t += c;
        sum += stoll(t) * mul;
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i <= MAX; i++) {
        if(check(i)) {
            ans1 = i;
            break;
        }
    }
    for (int i = MAX; i >= 0; i--) {
        if(check(i)) {
            ans2 = i;
            break;
        }
    }
    cout << ans1 << " " << ans2 << endl;
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
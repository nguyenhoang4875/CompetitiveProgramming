#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/gym/482326/problem/F
 * Using binary search to find t: that tC2 <= n
 * ans = t + n - tC2 
 * 
 * TC: O(log n)
 * MC: O(n)
 * 
*/

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 1e5 + 5;
int n;

bool check(int val) {
    return (val *(val - 1) / 2) <= n;
}

void solve() {
    cin >> n;

    int l = 1, r = 3e9;
    int t = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            t = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    int ans = t + n - t * (t - 1) / 2;
    cout << ans << el;

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
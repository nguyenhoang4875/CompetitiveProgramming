#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/group/AzS2VFYWhz/contest/482326/problem/O
 * Solution:
 * -  If a[i] is not choosen, it will flip k time;
 * -  If a[i] is choosen one time, it will flip k -1 time and so on.
 *  Make sure left element set 1 first
 *
 * TC: O(n)
 * MC: O(n)
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
const int ms = 2e5 + 5;
int n, k;
int a[ms];

void solve() {
    cin >> n >> k;
    int tk = k;
    vi cnt(n + 1, 0);
    For(i, 1, n) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    int t = 0;
    For(i, 1, n) {
        if (tk == 0) break;
        if ((a[i] == 0 && k % 2 == 0) || (a[i] == 1 && k % 2 == 1)) {
            tk--;
            cnt[i]++;
        }
        a[i] = 1;
        t = i;
    }
    if (t < n) {
        For(j, t + 1, n) {
            if (k & 1) a[j] ^= 1;
        }
    }
    if (tk > 0) {
        cnt[n] += tk;
        if (tk & 1) a[n] = 0;
    }
    For(i, 1, n) cout << a[i];
    cout << el;
    For(i, 1, n) cout << cnt[i] << " ";
    cout << el;
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
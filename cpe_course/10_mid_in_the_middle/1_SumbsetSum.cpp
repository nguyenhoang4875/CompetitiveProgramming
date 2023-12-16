#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/SUBSUMS/
 * Solution: Meet in the middle
 *  split the array to two part: left part and right part
 *  subset Sum all in left part
 *  then binary search to find all elements properly in right part
 *
 * TC: O(n * 2 ^ (n / 2))
 * MC: O(2 ^(n/2))
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
int n, a, b;

int getBit(int mask, int pos) { return (mask >> pos) & 1; }

vi getSum(vi &a) {
    int n = sz(a);
    vi sum;
    For(mask, 0, (1 << n) - 1) {
        int s = 0;
        for (int pos = 0; pos < n; pos++) {
            if (getBit(mask, pos)) s += a[pos];
        }
        sum.pb(s);
    }
    sort(all(sum));
    return sum;
}

void solve() {
    cin >> n >> a >> b;
    vi ha, hb;
    For(i, 0, n - 1) {
        int x;
        cin >> x;
        if (i < n / 2)
            ha.pb(x);
        else
            hb.pb(x);
    }

    vi sumA = getSum(ha);
    vi sumB = getSum(hb);

    int cnt = 0;
    for (auto e : sumA) {
        cnt += upper_bound(all(sumB), b - e) - lower_bound(all(sumB), a - e);
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
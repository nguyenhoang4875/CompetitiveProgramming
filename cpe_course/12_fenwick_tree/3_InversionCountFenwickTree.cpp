#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Inversion count
 * Count all pair that i < j and a[i] > a[j]
 *
 * Solution: using Fenwick Tree
 *  - Count all the j elements after i that a[j] < a[i]
 *
 * TC: O(n * log n)
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
const int ms = 1e5 + 5;
int n;
int a[ms];

struct FenwickTree {
    int n;
    vi t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    void add(int i, int val) {
        while (i <= n) {
            t[i] += val;
            i += i & (-i);
        }
    }
    int get(int i) {
        int sum = 0;
        while (i > 0) {
            sum += t[i];
            i -= i & -i;
        }
        return sum;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

void solve() {
    cin >> n;
    vii mp;  // can use multimap instead but slower
    For(i, 1, n) {
        int x;
        cin >> x;
        mp.pb({x, i});
    }
    sort(all(mp));
    FenwickTree ft(n);  // all element in ft is 0
    int cnt = 0;
    for (auto [f, s] : mp) {
        cout << f << " " << s << el;
        cnt +=
            ft.query(s + 1, n);  // count all element behind s is appear (< f)
        ft.add(s, 1);            // increase current position by 1
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
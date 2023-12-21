#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/DQUERY/
 *  Count distinct element in range [l, r]
 *
 * Solution: Using fenwick tree
 *  - sort query by ascending r value
 *  - only keep the right most index for the value
 *  - query when i == r
 *
 * TC: O((q + n) * log n)
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

struct node {
    int l, r, id;
};

bool cmp(node n1, node n2) { return n1.r < n2.r; }

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];

    int q;
    cin >> q;

    vector<node> vn(q);
    For(i, 0, q - 1) {
        int l, r;
        cin >> l >> r;
        vn[i] = {l, r, i + 1};
    }
    sort(all(vn), cmp);
    unordered_map<int, int> lastSeen;
    FenwickTree ft(n);
    vii ans;
    auto ne = vn.begin();
    For(i, 1, n) {
        if (lastSeen.count(a[i])) {
            ft.add(lastSeen[a[i]], -1);
        } else {
        }
        lastSeen[a[i]] = i;
        ft.add(i, 1);
        while (ne != vn.end() && ne->r == i) {
            int cnt = ft.query(ne->l, ne->r);

            ans.pb({cnt, ne->id});
            ne++;
        }
        if (ne == vn.end()) break;
    }
    sort(all(ans), [&](pii n1, pii n2) { return n1.S < n2.S; });
    for (auto [f, s] : ans) {
        cout << f << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
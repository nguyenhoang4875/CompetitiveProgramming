#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Using Segment Tree max query
 * - Each query find the smallest index i: a[i] >= x(number of people)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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
int n, m;

vi tree;
int query(int v, int l, int r, int val) {
    if (l == r) {
        return l;
    } else {
        int mid = (l + r) / 2;
        if (tree[2 * v] >= val)
            return query(2 * v, l, mid, val);
        else
            return query(2 * v + 1, mid + 1, r, val);
    }
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr)
        tree[v] += val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, val);
        } else
            update(2 * v + 1, tm + 1, tr, pos, val);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }
}

void solve() {
    cin >> n >> m;
    tree.resize(4 * n);
    For(i, 1, n) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }

    while (m--) {
        int x;
        cin >> x;
        if (tree[1] < x)
            cout << "0 ";
        else {
            int pos = query(1, 1, n, x);
            update(1, 1, n, pos, -x);
            cout << pos << " ";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();

    return 0;
}
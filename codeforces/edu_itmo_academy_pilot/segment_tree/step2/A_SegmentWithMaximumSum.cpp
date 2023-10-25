#include <bits/stdc++.h>
#define int long long

using namespace std;
/*
Approach
In these kind of problems we require four variables for each segment of the
segment tree
    Sum - Stores the sum of the segment
    Suff -Stores the maximum suffix sum of the segment
    Pref - Stores the maximum prefix sum of the segment
    Ans - Stores the ans that is the maximum sum of the segment

Updation
    Left child - L, Right child - R.  Then the parent P’s properties are
    P.sum = L.sum + R.sum
    P.pref = max(L.pref, L.sum + R.pref)
    P.suff = max(R.suff, R.sum + L.suff)
    P.ans = max(L.ans, R.ans, L.suff + R.pref)


*/

#define pb push_back
#define all(x) x.begin(), x.end()
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

struct item {
    int sum, pref, suff, ans;
};
vector<item> tree;

item combine(item i1, item i2) {
    item i;
    i.sum = i1.sum + i2.sum;
    i.pref = max(i1.pref, i1.sum + i2.pref);
    i.suff = max(i2.suff, i2.sum + i1.suff);
    i.ans = max({i1.suff + i2.pref, i1.ans, i2.ans});
    return i;
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        if (val <= 0) {
            tree[v].sum = val;
            tree[v].pref = tree[v].suff = tree[v].ans = 0;
        } else {
            tree[v].sum = tree[v].pref = tree[v].suff = tree[v].ans = val;
        }
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
    }
}

int getSumMax() { return tree[1].ans; }

void solve() {
    int n, m;
    cin >> n >> m;
    tree.resize(4 * n);

    For(i, 1, n) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    cout << getSumMax() << "\n";
    while (m--) {
        int a, b;
        cin >> a >> b;
        update(1, 1, n, ++a, b);
        cout << getSumMax() << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
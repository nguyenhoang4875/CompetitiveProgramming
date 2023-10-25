#include <bits/stdc++.h>
#define int long long

using namespace std;

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

vi tree;
void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, val);
        else
            update(2 * v + 1, tm + 1, tr, pos, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int findKth(int v, int tl, int tr, int k) {
    if (k > tree[v]) return -1;
    if (tl == tr)
        return tl;
    else {
        int tm = (tl + tr) / 2;
        if (k <= tree[2 * v])
            return findKth(2 * v, tl, tm, k);
        else
            return findKth(2 * v + 1, tm + 1, tr, k - tree[2 * v]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    tree.resize(4 * n);
    For(i, 1, n) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }

    while (m--) {
        int type, val;
        cin >> type >> val;
        val++;
        if (type == 1) {
            a[val] ^= 1;
            update(1, 1, n, val, a[val]);
        } else {
            cout << findKth(1, 1, n, val) - 1 << "\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
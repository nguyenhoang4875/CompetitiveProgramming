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
    if(tl == tr) tree[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2 * v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = tree[2*v] + tree[2*v +1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tl > r or tr < l) return 0;
    if(l <= tl and tr <= r) return tree[v];
    
    int tm = (tl + tr) / 2;
    return query(2*v, tl, tm, l, r) + query(2*v + 1, tm + 1, tr, l, r);
}

void solve() {
    cin >> n;
    tree.resize(4 * n);

    For(i, 1, n) {
        int x;
        cin >> x;
        cout << query(1, 1, n, x + 1, n) << ' ';
        update(1, 1, n, x, 1);
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
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

int combine(int v1, int v2) {
    return max(v1, v2);
}

void update(int v, int tl, int tr, int pos, int val) {
    if(tl == tr) tree[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) update(2 * v, tl, tm, pos, val);
        else update(2*v + 1, tm + 1, tr, pos, val);
        tree[v] = combine(tree[2*v], tree[2*v +1]);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if(tl > r or tr < l) return -oo;
    if(l <= tl and tr <= r) return tree[v];
    
    int tm = (tl + tr) / 2;
    return combine(query(2*v, tl, tm, l, r), query(2*v + 1, tm + 1, tr, l, r));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    tree.resize(4*n) ;
    For(i, 1, n) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    while(m--) {
        int type;
        cin >> type;
        if(type == 1) {
            int pos, val;
            cin >> pos >> val;
            update(1, 1, n, ++pos, val);
        } else {
            int x, il;
            cin >> x >> il;
            int ans = -1;
            int l = il + 1, r = n;
            while(l <= r) {
                int mid = (l + r) /2;
                if(query(1, 1, n, l, mid) >= x) {
                    ans = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }
            if(ans != -1) ans -= 1;
            cout << ans << '\n';
        }
    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
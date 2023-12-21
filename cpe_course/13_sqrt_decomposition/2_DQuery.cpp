#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/DQUERY/
 * Count distinct element in range [l, r]
 *
 * TC: O((q + n) * sqrt(n))
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
const int ms = 1e6 + 5;
int cnt[ms];
int dst = 0;

struct node {
    int l, r, id, b, ans;
};
bool cmp1(node &n1, node &n2) {
    if (n1.b == n2.b) return n1.r < n2.r;
    return n1.b < n2.b;
}

bool cmp2(node &n1, node &n2) { return n1.id < n2.id; }

void add(int val) {
    cnt[val]++;
    if (cnt[val] == 1) dst++;
}
void remove(int val) {
    cnt[val]--;
    if (cnt[val] == 0) dst--;
}

void solve() {
    int n, m, q;
    cin >> n;
    vi a(n);
    For(i, 0, n - 1) cin >> a[i];

    m = sqrt(n);
    cin >> q;
    vector<node> vn(q);
    For(i, 0, q - 1) {
        cin >> vn[i].l >> vn[i].r;
        vn[i].l--, vn[i].r--;
        vn[i].id = i;
        vn[i].b = vn[i].l / m;
    }
    sort(all(vn), cmp1);

    int x = 0, y = -1;  // y = -1 to take all values in range: [x, y]
    For(i, 0, q - 1) {
        int l = vn[i].l;
        int r = vn[i].r;

        // adding l
        while (x > l) {
            x--;
            add(a[x]);
        }

        while (x < l) {
            remove(a[x]);
            x++;
        }

        // adding y
        while (y < r) {
            y++;
            add(a[y]);
        }
        while (y > r) {
            remove(a[y]);
            y--;
        }
        vn[i].ans = dst;
    }
    sort(all(vn), cmp2);
    For(i, 0, q - 1) { cout << vn[i].ans << el; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
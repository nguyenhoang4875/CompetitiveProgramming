#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://oj.vnoi.info/problem/kquery
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

const int maxN = 3e4;
int n, k, a[maxN];
vi st[maxN * 4];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    vi tmp(st[id * 2].size() + st[id * 2 + 1].size());
    st[id] = tmp;
    merge(st[id * 2].begin(), st[id * 2].end(), st[id * 2 + 1].begin(), st[id * 2 + 1].end(),
          st[id].begin());
}

int get(int id, int l, int r, int u, int v, int val) {
    if (l > v or r < u) return 0;
    if (l >= u and r <= v)
        return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), val) - st[id].begin());
    int mid = (l + r) >> 1;
    return get(id * 2, l, mid, u, v, val) + get(id * 2 + 1, mid + 1, r, u, v, val);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    For(i, 1, n) cin >> a[i];
    build(1, 1, n);
    cin >> k;
    while (k-- > 0) {
        int l, r, val;
        cin >> l >> r >> val;
        cout << get(1, 1, n, l, r, val) << '\n';
    }
}
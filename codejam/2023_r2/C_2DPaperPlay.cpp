#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define ff first
#define ss second

using namespace std;

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
    vector<int> tree;
    int n;

    FenwickTree(int _n) {
        tree.resize(_n + 1);
        n = _n;
    }

    int get(int idx) {
        int ans = 0;
        while (idx) {
            ans += tree[idx];
            idx -= idx & -idx;
        }
        return ans;
    }

    void update(int idx, int val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx;
        }
    }

    int getRange(int l, int r) { return get(r) - get(l - 1); }
};

const int oo = 1e18, mod = 1e9 + 7;
int n, m, q;
vector<pii> blocks;
vector<pii> sheets;

void solve() {
    cin >> n >> m >> q;

    blocks.clear();
    int xx, yy;
    for (int i = 0; i < n; i++) {
        cin >> yy >> xx;
        blocks.pb({xx, yy});
    }
    sheets.clear();
    FenwickTree fwTree(100005);
    for (int i = 0; i < m; i++) {
        cin >> yy >> xx;
        sheets.pb({xx, yy});
        fwTree.update(yy, 1);
    }

    sort(blocks.begin(), blocks.end());
    sort(sheets.begin(), sheets.end());

    vi C(50005, 0);
    int initCnt = m;
    int j = 0;
    for (int i = 0; i < n; i++) {
        // count for rows
        auto block = blocks[i];
        while (j < sheets.size() && sheets[j].ff < block.ff) {
            fwTree.update(sheets[j].ss, -1);
            initCnt--;
            j++;
        }

        // count for columns
        C[i] = initCnt - fwTree.get(block.ss - 1);
    }
    for (int i = 0; i < n; i++) {
        cout << C[i] << " ";
    }
    cout << '\n';

    vi D(m + 5, 0);
    for (int i = 0; i < blocks.size(); i++) {
        D[C[i]]++;
    }
    for (int i = 1; i <= m; i++) {
        D[i] += D[i - 1];
    }

    while (q--) {
        cin >> xx >> yy;
        if (xx == 0)
            cout << D[yy] << " ";
        else
            cout << D[yy] - D[xx - 1] << " ";
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
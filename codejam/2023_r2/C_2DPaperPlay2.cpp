#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

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
    int n;
    vi tree;
    FenwickTree(int _n) {
        n = _n;
        tree.resize(n, 0);
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
};

const int oo = 1e18, mod = 1e9 + 7;
int n, m, q;

void solve() {
    cin >> n >> m >> q;
    vii blocks;
    vii sheets;

    int xx, yy;
    for (int i = 0; i < n; i++) {
        cin >> yy >> xx;
        blocks.pb({xx, yy});
    }
    FenwickTree fwTree(100005);
    for (int i = 0; i < m; i++) {
        cin >> yy >> xx;
        sheets.pb({xx, yy});
        fwTree.update(yy, 1);
    }

    sort(all(blocks));
    sort(all(sheets));

    vi C(50005, 0);
    int initCnt = m;
    int j = 0;

    for (int i = 0; i < n; i++) {
        // count for rows
        auto block = blocks[i];
        while (j < sheets.size() && sheets[j].first < block.first) {
            initCnt--;
            fwTree.update(sheets[j].second, -1);
            j++;
        }

        // count for columns
        C[i] = initCnt - fwTree.get(block.second - 1);
    }
    vi D(m + 5);
    for (int i = 0; i < n; i++) {
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
    cout << "\n";
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
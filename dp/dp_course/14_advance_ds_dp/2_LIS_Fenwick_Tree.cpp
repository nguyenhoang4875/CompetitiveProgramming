#include <bits/stdc++.h>
#define int long long
#define pb push_back

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
    vector<int> fn;
    int n;

    FenwickTree(int _n) {
        n = _n + 2;
        fn.clear();
        fn.resize(n, 0);
    }

    void update(int idx, int val) {
        idx++;  // base index 1
        while (idx < n) {
            fn[idx] = max(fn[idx], val);
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;
        int ans = 0;
        while (idx) {
            ans = max(ans, fn[idx]);
            idx -= idx & -idx;
        }
        return ans;
    }
};

const int oo = 1e18, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    pii b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }

    FenwickTree ft(n);
    int lis[n];
    int l;
    cin >> l;

    if(n == 0) {
        cout << -1 << endl;
        return;
    }

    sort(b, b + n);
    for(int i = 0; i < n; i++) {
        int val = b[i].first;
        int index = b[i].second;
        lis[index] = ft.query(index - 1) + 1;
        ft.update(index, lis[index]);
        if(lis[index] == l) {
            cout << val << endl;
            return;
        }
    }
    cout << -1 << endl;

    // cout << ft.query(n - 1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}
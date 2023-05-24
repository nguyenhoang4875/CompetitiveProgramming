#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

vector<int> ans;
vector<int> b;
bool gr() {
    for (int i = 0; i < n; i++) {
        if(ans[i] == b[i]) continue;
        else {
            if(ans[i] < b[i]) return true;
            else return false;
        }
    }
    return false;
}

void work(vector<int> &a, int l, int r) {
    // cout << "l = " << l << " r = " << r << endl;
    b.clear();
    for(int i = r + 1; i < n; i++) b.push_back(a[i]);
    int idx = l;
    for(int i = r ; i >= l; i--) {
        b.push_back(a[i]);
    }
    for (int i = 0; i < l; i++) b.push_back(a[i]);
    if(l == 0 && r == 0) {
       for (int i = 0; i < n; i++) ans[i] = b[i];
    }
    if(gr()) {
       for (int i = 0; i < n; i++) ans[i] = b[i];
    }
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // for (int i = 0; i < n; i++) ans[i] = a[i];
    ans.clear();
    for(int i = 0; i < n; i++) {
        ans.push_back(a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            work(a, i, j);
        }
    }
    for (int e: ans) cout << e << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
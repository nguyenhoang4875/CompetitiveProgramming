#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];
int b[200005];

void solve() {
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << "2 1" << endl;
        return;
    }
    if (n == 3) {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; i++) {
        if(i % 2 == 1) {
            b[i] = l++;
        } else {
            b[i] = r--;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    
    a[1] = n;
    a[2] = n - 1;
    int sum = a[1] + a[2];
    int cnt = 1;
    set<int> si;
    si.insert(a[1]);
    si.insert(a[2]);
    for (int i = 3; i <= n; i++) {
        while (cnt * n + b[i] < sum) {
            cnt++;
        }
        a[i] = cnt * n + b[i] - sum;
        sum += a[i];
        if(si.count(a[i])) {
            cout << -1 << endl;
            return;
        }
        si.insert(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
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
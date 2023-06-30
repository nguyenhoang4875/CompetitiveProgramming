#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int start;
    int prePos;
    for (int i = 1; i <= n; i++) {
       if(i == 1) {
            cout << 1;
            prePos = 1;
            start = 1;
            continue;
       }
       if(i == 2) {
            cout << 1;
            prePos = 2;
            if(a[1] > a[2]) start = 2;
            continue;
       }
       if(start == 1) {
            if(a[i] >= a[prePos]) {
                cout << 1;
                prePos = i;
            } else if(a[i] <= a[1]) {
                cout << 1;
                prePos = i;
                start = i;
            } else {
                cout << 0;
            }
       } else {
            if(a[i] >= a[prePos] && a[i] <= a[1]) {
                cout << 1;
                prePos = i;
            } else {
                cout << 0;
            }
       }
    }

    cout << '\n'; 
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
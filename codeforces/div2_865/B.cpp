#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
// int MAX = 100005;
int a[3][100005];

void solve() {
    cin >> n;
    a[1][1] = 2*n;
    a[2][n] = 2*n - 1;
    int r = 1;
    int base = 1;
    int up = 2*n - 2;
    for (int i = 2; i <= n ; i++) {
        if(i % 2 == 0) {
            a[1][i] = base * 2;
            base++;
        } else {
            a[1][i] = up;
            up -= 2;
        }
    }

    base = 1;
    up = 2*n - 3;
    for(int i = 1; i < n ; i++) {
        if(i % 2 == 1) {
            a[2][i] = base;
            base+= 2;
        } else {
            a[2][i] = up;
            up-= 2;
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= n ; j++) {
            cout << a[i][j] <<" ";
        }
        cout << endl;
    }
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
#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
char a[5][5];

bool checkTic(char c) {
    for(int i = 1; i<= 3; i++) {
        if(a[i][1] == c && a[i][1] == a[i][2] && a[i][1] == a[i][3]) return true;
    }
    for(int i = 1; i<= 3; i++) {
        if(a[1][i] == c && a[1][i] == a[2][i] && a[1][i] == a[3][i]) return true;
    }
    if(a[1][1] == c && a[1][1] == a[2][2] && a[1][1] == a[3][3]) return true;
    if(a[1][3] == c && a[1][3] == a[2][2] && a[1][3] == a[3][1]) return true;
    return false;
}

void solve() {
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cin >> a[i][j];
        }
    }

    if(checkTic('+')) {
        cout << "+\n";
        return;
    }
    if(checkTic('O')) {
        cout << "O\n";
        return;
    }
    if(checkTic('X')) {
        cout << "X\n";
        return;
    }
    cout << "DRAW\n";


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
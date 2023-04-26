#include<bits/stdc++.h>

using namespace std;

int tcs, r, c, k;
string s;
int a[510][15];
const int MOD = 1e9 + 7;


char flip(char c) {
    if(c == '+') return '-';
    else return '+';
}
int maxSwitch() {
    int cnt = 0;
    for (int i = 1;  i <= r; i++) {
        int temp = 0;
        for (int j = 1; j <= c ; j++){
            if(a[i][j] == 0) temp++;
            else {
                cnt += temp / 2;
                temp = 0;
            }
        }
        cnt += temp / 2;
    }
    cout << "cnt = " << cnt << endl;
    return cnt;
}

void clearArray() {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c ; j++) {
            a[i][j] = 0;
        }
    }
}

void solve() {
    clearArray();
    cin >> r >> c >> k;
    cin >> s;
    s = " " + s;
    int x, y;
    for (int i = 1; i <= k ; i++) {
       cin >> x >> y;
       a[x][y] = -1;
    }
    for (int col = 1; col <= c; col++) {
        for (int row = 1; row <= r; row++) {
            if(a[row][col] == -1) s[col] = flip(s[col]);
        }
    }
    cout << "s = " << s << endl;
    int ms = maxSwitch();
    cout << "max switch = " << ms << endl;


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
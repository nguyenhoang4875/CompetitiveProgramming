#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1789/problem/B
*/
int tcs, n;
vector<int> vi;

void solve() {
    cin >> n;
    string s;
    cin >> s;

    int ist = 0;
    int ils = 0;
    int half = n / 2;
    for (int i = 0 ;i <= half; i++) {
        if(s[i] != s[n-1-i]) {
            ist = i;
            break;
        }
    }
    for (int i = half;i >= 0; i--) {
        if(s[i] != s[n-1-i]) {
            ils = i;
            break;
        }
    }
    // cout << "ist = " << ist << " ils = " << ils << endl;
    if(ist == ils) {
        cout << "Yes" << endl;
        return;
    }
    for (int i = ist; i <= ils; i++) {
        if(s[i] == s[n-1-i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
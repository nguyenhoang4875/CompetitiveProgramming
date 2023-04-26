#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;
string d;

char c[200005];

void solve() {
    cin >> n; 
    cin >> d;
    cin >> s;
    bool found = false;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] >= d[0]) {
            c[idx] = s[i];
        } else {
            if(!found) {
                c[idx] = d[0];
                i--;
                found = true;
            } else c[idx] = s[i];
        }
        idx++;
    }
    if(!found) {
        c[n] = d[0];
    }
    for (int i = 0; i <= n; i++) {
        cout << c[i];
    }
    cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        // cout << "tcs = " << tcs << endl;
        solve();
    }
    return 0;
}
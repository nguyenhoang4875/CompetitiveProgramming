#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string a[3];
string s;

struct node {
    int r, c;
};

int cal(int r1, int c1, int r2, int c2) {
    return max({abs(r1 - r2 + c1 - c2), abs(r1 -r2), abs(c1 - c2)});
}

void solve() {
    cin >> s;
    n = s.size();
    vector<node> vn(n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            for (int k = 0; k < 10; k++) {
                if(a[j][k] == s[i]) {
                    vn[i] = {j, k};
                    break;
                }
            }
        }
    }
    int ans = n;
    for (int i = 0; i < n - 1; i++) {
        int temp = cal(vn[i].r, vn[i].c, vn[i+1].r, vn[i+1].c);
        // cout << "temp = " << temp << endl;
        ans += 2*temp;
    }
    cout << ans << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    a[0] = "QWERTYUIOP";
    a[1] = "ASDFGHJKL ";
    a[2] = "ZXCVBNM   "; 

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k;
string s[10];

int g[15];
bool used[15];
int ans = INT_MAX;

int getNum(string st) {
    int num = 0;
    for (int i = 1; i <= k; i++) {
        num *= 10;
        num += st[g[i]] - '0';
    }
    return num;
}

int cacl() {
    int mm = INT_MAX;
    int mx = INT_MIN;
    for (int i= 1; i <= n; i++) {
        // cout << "si = " << s[i] << endl;
        int num = getNum(s[i]);
        // cout << "num ="  << num << endl;

        mm = min(mm, num);
        mx = max(mx, num);
    }
    return mx - mm;
}

void gen(int idx) {
    if(idx > k ) {
        // for (int i = 1; i <= k ; i++) {
        //     cout << g[i];
        // }
        // cout << endl;
        ans = min(ans, cacl());
    } else {
        for (int val = 1; val <= k; val++) {
            if(used[val]) continue;
            g[idx] = val;
            used[val] = true;
            gen(idx + 1);
            used[val] = false;
        }
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        s[i] = " " + tmp;
    }
    gen(1);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // cin >> tcs;
    tcs = 1;
    
    while(tcs-- > 0) {
        solve();
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int g[15];
bool used[15];

void gen(int idx) {
    if(idx > n ) {
        for (int i = 1; i <= n ; i++) {
            cout << g[i];
        }
        cout << endl;
    } else {
        for (int val = 1; val <= n; val++) {
            if(used[val]) continue;
            g[idx] = val;
            used[val] = true;
            gen(idx + 1);
            used[val] = false;
        }
    }
}
void solve() {
    cin  >> n;
    gen(1);

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
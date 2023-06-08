#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    int idn, id1, id2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 1) id1 = i;
        if(a[i] == 2) id2 = i;
        if(a[i] == n) idn = i;
    } 

    int l = 0, r = 0;
    int idMin = min({id1, id2, idn});
    int idMax = max({id1, id2, idn});
    if(idMin == idn) {
        l = idn;
        r = min(id1, id2);
    } else if (idMax == idn) {
        l = idn;
        r = max(id1, id2);
    } else {
        l = id1;
        r = id2;
    }
    cout << l << " " << r << "\n";

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
#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    int a, b;
    cin >> a >> b;
    int x = gcd(a, b);
    if(x == 1) {
        cout << 1 << endl;
        cout << a << " " << b << endl;
        return;
    }
    bool found = false;
    for (int pa = 1; pa < a; pa++) {
        for (int pb = 1; pb < b; pb++) {
            int xp1 = gcd(pa, pb);
            int xp2 = gcd(a -pa, b - pb);
            if(xp1 == 1 && xp2 == 1) {
                cout << 2 << endl;
                cout << pa << " " << pb << endl;
                cout << a << " " << b << endl;
                return;
            }
        }
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
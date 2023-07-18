#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, k, x;

void solve() {
    cin >> n >> k >> x;
    if(k == 1 && x == 1) {
        cout << "NO\n";
        return;
    } 
    if(n % 2 == 1 && k == 2 && x == 1) {
        cout << "NO\n";
        return;
    }
   cout << "YES\n";
   if(x != 1) {
        cout << n << '\n';
        for(int i = 1; i <= n ; i++) cout << "1 ";
        cout << '\n';
   } else {
        if(n & 1) {
            int num = (n - 3) / 2 + 1;
            cout << num << endl;
            for(int i = 1; i < num ; i++) cout << "2 ";
            cout << 3 << '\n';
        } else {
            int num = n / 2;
            cout << num << endl;
            for(int i = 1; i <= num; i++) cout << "2 ";
            cout << '\n';
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
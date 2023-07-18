#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
set<int> s;
int oo = 1e6;

int power(int a, int n) {
    if(n == 0) return 1; // base case
    return a * power(a, n - 1); // rec case
}

void pre() {
    for(int i = 2; i <= 1000; i++) {
        int sum = 1 + i;
        int cnt = 2;
        while(sum <= oo) {
            sum += power(i, cnt);
            // cout << "sum = " << sum << endl;
            s.insert(sum);
            cnt++;
        }
    }
}

void solve() {
    cin >> n;
    if(s.count(n)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
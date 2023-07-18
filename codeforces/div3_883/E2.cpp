#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
set<int> s;
int oo = 1e18;


void preCalculate() {
    for(int k = 2; k <= 1e6; k++) {
        int sum = 1 + k;
        int p = k * k;
        for(int cnt = 3; cnt <= 63; cnt++) {
            sum += p;
            if(sum > oo) break;
            s.insert(sum);
            if(p > oo / k) break;
            p *= k;
        }
    }
}

void solve() {
    cin >> n;
    if(n < 7) {
        cout << "NO\n";
        return;
    }
    if(s.count(n)) {
        cout << "YES\n";
        return;
    }
    // if k > 10 ^ 6 only the case: 1 + k + k^2 
    n--;
    int k = floor(sqrt(n));
    if(k * (k + 1) == n || (k - 1) * k == n) {
        cout << "YES\n";
        return;
    } 
    cout << "NO\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    preCalculate();

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
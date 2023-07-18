#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
double d, h;

int a[200005];
// dobule esp = -1e
void solve() {
    cin >> n >> d >> h;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    double oneTri = 1.0 * d * h / 2.0; 
    // cout << "oneTri = " << oneTri << endl;
    double sum = 0;
    double et = 0;
    for(int i = 1; i <= n - 1; i++) {
        double dh = a[i + 1] - a[i];
        if(dh >= 1.0*h) et = oneTri;
        else et = oneTri - (1.0* (h*1.0 - dh) / h) * (1.0* (h*1.0 - dh) /h) * oneTri;
        sum += et;
    }
    sum += oneTri;
    cout << fixed;
    cout.precision(7);
    cout << sum << "\n";

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
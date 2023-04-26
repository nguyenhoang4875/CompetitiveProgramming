#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int x;
double sum;
int MAX = 1e4;

void solve() {
    sum = 0;
    cin >> n;
    cin >> x;
    double pi;
    for (int i = 1; i <= n; i++) {
        cin >> pi;
        sum += pi;
    }
    double tax_min;
    double tax_max;
    int mnv;
    int mxv;
    // if(x == 0) {
    //     x = sum;
    //     tax_min = 0;
    //     tax_max = 1 - sum;
    //     mnv = 0;
    //     for (int i = 1; i <= MAX; i++) {
    //         if((i * sum) >= (tax_max * 100)) {
    //             mxv = i - 1;
    //             break;
    //         }
    //     }
    //     cout << mnv << " " << mxv << endl;
    // } else {
        tax_min = 1.0*(x - sum) * 100.0;
        for (int i = 0; i <= MAX; i++) {
            double temp = ceill(i * sum);
            if(temp >= tax_min) {
                mnv = i;
                break;
            } 
        }
        tax_max = 1.0*(x - sum + 1) * 100.0;
        for (int i = 0 ; i <= MAX; i++) {
            double temp = i * sum;
            if(temp >= tax_max) {
                mxv = i - 1;
                break;
            } 
        }
        cout << mnv << " " << mxv << endl;
    }

// }

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
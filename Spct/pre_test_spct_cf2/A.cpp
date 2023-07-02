#include <iostream>
#define int long long

using namespace std;
/**
 * Check the B and C is same side of A or different side.
 * If same side: distance by x axis = min(abs(xb - xa), abs(x)) => same for y axis
 * If different side: distance = 0
*/

int tcs, n;

int xa, xb, xc;
int ya, yb, yc;

void solve() {
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    int minX = 0;
    int minY = 0;
    if(((xb - xa) > 0) == ((xc - xa) > 0)) {
        minX = min(abs(xb - xa), abs(xc - xa));
    }
    if(((yb - ya) > 0) == ((yc - ya) > 0)) {
        minY = min(abs(yb - ya), abs(yc - ya));
    }
    cout << (minX + minY + 1) << '\n';

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
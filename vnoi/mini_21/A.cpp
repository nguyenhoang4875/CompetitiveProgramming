#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int oo = 2e9;
int a, b, x, y;


void solve() {
    cin >> a >> b >> x >> y;

    int sum = oo;
    for(int i = 0; i <= 10000; i++) {
        int t = (i + a) * x / y;
        if(t < b) continue;
        if((t * y) == (i + a) * x) {
            sum = min(sum, i + t - b);
        }
      
    }
    if(sum == oo) sum = -1;
    cout << sum << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
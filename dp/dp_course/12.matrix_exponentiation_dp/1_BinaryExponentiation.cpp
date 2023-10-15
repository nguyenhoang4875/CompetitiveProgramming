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

const int oo = 1e18, mod = 1e9 + 7;
int n;

int powerExp(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b /= 2;
        a *= a;
    }
    return ans;
}
void solve() {
    int a, b;
    cin >> a >> b;
    cout << powerExp(a, b);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
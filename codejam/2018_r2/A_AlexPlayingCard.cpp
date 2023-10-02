#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
int n;

void solve() {
    cin >> n;
    n = 52 - n;
    // cout << "n = " << n << '\n';

    int aMax = min(n / 5, 8LL);
    int aMin = 0;
    int t = n;
    if(t > 26) {
        t -= 26;
        while (t > 0) {
            t -= 2;
            aMin++;
        }
        aMin = min(aMin, 8LL);
    }
    if(n == 39 || n == 40) aMin = 6;
    if(n == 41 || n == 42 || n == 43) aMin = 7;

    cout << aMin << " " << aMax << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
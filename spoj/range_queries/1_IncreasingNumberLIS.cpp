#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 1e5 + 5;
int n, l;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
    }
    cin >> l;
    if(n == 0 || l > n) {
        cout << -1 << el;
        return;
    }
    vi lis;
    lis.pb(a[1]);
    For(i, 2, n) {
        if(a[i] > lis.back()) {
            lis.pb(a[i]);
        } else {
            int pos = lower_bound(all(lis), a[i]) - lis.begin();
            lis[pos] = a[i];
        }
    }
    if(l > sz(lis)) {
        cout << "-1" << el;
    } else  cout << lis[l - 1] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}
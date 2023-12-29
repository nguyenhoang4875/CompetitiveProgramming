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
int n;

void solve() {
    cin >> n;
    vi a(n);
    for(auto &x: a) cin >> x;
    if(n == 1) {
        cout << "YES\n";
        cout << "1" << el;
        cout << "1" << el;
        return;
    }
    map<int, int> mii;
    for(auto x: a) {
        mii[x]++;
    }
    int sn = sz(mii);
    if(sn < n - 1) {
        cout << "NO" << el;
        return;
    }
    vi b = a;
    sort(all(b));
    for(int i = 0; i < n; i++) {
        if(a[i] < i + 1) {
            cout << "NO\n";
            return;
        }
    }

    // have all value in permutation



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
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
vii v;
void solve() {
    cin >> n;
    v = vii(n);
    For(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        v[i] = {b, a};
    }

    sort(all(v));
    int l = 0, r = n - 1;
    int ans = 0;
    while (l <= r) {
        ans = max(ans, v[l].F + v[r].F);
        if (v[l].S < v[r].S) {
            v[r].S -= v[l].S;
            l++;
        } else if (v[l].S > v[r].S) {
            v[l].S -= v[r].S;
            r--;
        } else {
            l++;
            r--;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
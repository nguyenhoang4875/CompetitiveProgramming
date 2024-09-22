#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int a[ms];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    function<int(int)> getPower2 = [](int val) {
        int cnt = 0;
        while (val % 2 == 0) {
            cnt++;
            val /= 2;
        }
        return cnt;
    };

    int c2 = 0;
    For(i, 1, n) { c2 += getPower2(a[i]); }

    if (c2 >= n) {
        cout << 0 << el;
        return;
    }

    int tmp = n;
    int mc = 0;
    while (tmp >= 2) {
        mc++;
        tmp /= 2;
    }
    vi v2;
    for (int i = n; i >= 1; i--) {
        v2.pb(getPower2(i));
    }
    sort(all(v2), greater<int>());
    int ans = 0;
    for (int i = 0; i < v2.size(); i++) {
        ans++;
        c2 += v2[i];
        if (c2 >= n) {
            cout << ans << el;
            return;
        }
    }

    cout << -1 << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
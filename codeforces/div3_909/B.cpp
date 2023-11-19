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
const int ms = 150000 + 5;
int n;
int a[ms];
int aa[ms];


vector<int> getDivisors(int n) {
    vector<int> vDiv;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            vDiv.push_back(i);
            if(i == 1) continue;
            if (i * i != n) vDiv.push_back(n / i);
        }
    }
    return vDiv;
}

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    if(n == 1) {
        cout << 0 << el;
        return;
    }
    vi vDiv = getDivisors(n);
    // for(auto e: vDiv) cout << e << " ";
    // cout << el;
    For(i, 1, n) {
        aa[i] = aa[i - 1] + a[i];
    }
    int ans = 0;
    for(auto len: vDiv) {
        int mMin = oo;
        int mMax = 0;
        int i = 0;
        while(i + len <= n) {
            i += len;
            int temp = aa[i] - aa[i - len];
            mMin = min(mMin, temp);
            mMax = max(mMax, temp);

        }
        ans = max(ans, mMax - mMin);
        if(len == n) ans = mMin;
    }
    cout << ans << el;

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
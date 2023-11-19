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
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    if(n == 1) {
        cout << a[1] << el;
        return;
    }
    int ans = -oo;
    int sum = 0;
    For(i, 2, n + 1) {
        // cout << "i = " << i  << el;
        sum += a[i - 1];
        // cout << "sum = " << sum << el;
        ans = max(ans, sum);
        sum = max(sum, 0LL);
        int cnt = 0;
        while(i <= n && abs(a[i - 1] % 2) != abs(a[i] % 2)) {
            sum += a[i];
            ans = max(ans, sum);
            sum = max(sum, 0LL);
            i++;
            cnt++;
        }
        // cout << "i2 = " << i  << el;
        sum = 0;
        // if(cnt) i--;
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
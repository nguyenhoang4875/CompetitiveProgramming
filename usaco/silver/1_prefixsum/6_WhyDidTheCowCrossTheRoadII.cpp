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
int n, k, b;

void solve() {
    cin >> n >> k >> b;
    vi need(n + 1);
    For(i, 1, b) {
        int x;
        cin >> x;
        need[x]++;
    }
    vi ps(n + 1);
    For(i, 1, n) {
        ps[i] = ps[i - 1] + need[i];
    }
    int ans = oo;
    For(i, k, n) {
        ans = min(ans, ps[i] - ps[i - k]);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    solve();
    return 0;
}
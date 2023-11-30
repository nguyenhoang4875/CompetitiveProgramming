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
const int ms = 3e5 + 5;
int n, m;
int a[ms];
int b[ms];

void solve() {
    cin >> n;
    int sum = 0;
    For(i, 1, n) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> m;
    For(i, 1, m) cin >> b[i];

    sort(a + 1, a + n + 1, greater<int>());

    int maxFree = 0;
    For(i, 1, m) { cout << sum - a[b[i]] << el; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}
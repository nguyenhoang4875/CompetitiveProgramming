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
int a[ms];
int preGcd[ms], sufGcd[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) { preGcd[i] = __gcd(preGcd[i - 1], a[i]); }
    Ford(i, n, 1) { sufGcd[i] = __gcd(sufGcd[i + 1], a[i]); }
    int ans = preGcd[n];
    For(i, 1, n) { ans = max(ans, __gcd(preGcd[i - 1], sufGcd[i + 1])); }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
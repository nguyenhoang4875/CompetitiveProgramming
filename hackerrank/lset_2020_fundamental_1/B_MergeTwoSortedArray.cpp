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
int a[ms], b[ms], c[ms];
int n, m;

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    cin >> m;
    For(i, 1, m) cin >> b[i];
    int l = 1, r = 1;
    int i = 1;
    //

    while (l <= n && r <= m) {
        if (a[l] <= b[r]) {
            c[i] = a[l];
            l++;
        } else {
            c[i] = b[r];
            r++;
        }
        i++;
    }
    while (l <= n) c[i++] = a[l++];
    while (r <= m) c[i++] = b[r++];
    For(i, 1, n + m) cout << c[i] << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}
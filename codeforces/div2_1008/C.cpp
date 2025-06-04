#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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

void solve() {
    int n;
    cin >> n;
    n *= 2;
    vi a(n);
    for (auto& x : a) cin >> x;
    sort(all(a));
    int l = a[n - 1];
    int pl = a[n - 2];
    a.pop_back();
    a.pop_back();
    n = a.size();
    int sum = 0;
    for (int i = 0; i < n / 2; i++) {
        sum += a[i] - a[i + n / 2];
    }
    int val = l + pl - sum;
    cout << l << " ";
    for (int i = 0; i < n / 2; i++) {
        cout << a[i] << " " << a[i + n / 2] << " ";
    }
    cout << val << " " << pl << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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
int n, a , b, k;

int cal(int n, int a, int b, int k) {
    int sum = -(k * k) + ( 2 * b - 2 * a + 1) * k + 2 * n * a;
    sum /= 2;
    return sum;
}
int ss(int n) {
    return n * (n + 1) / 2;
}

void solve() {
    cin >> n >> a >> b;
    if(b <= a) {
        cout << n * a << el;
        return;
    }
    if(b - a > n) {
        int r = b;
        int l = b - n + 1;
        int sum = ss(r) - ss(l - 1);
        cout << sum << el;
        return;
    }
    int k1 = (b - a);
    int k2 = (b - a + 1);
    int ans = max(cal(n, a, b, k1), cal(n, a, b, k2));
    cout << ans << el;

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
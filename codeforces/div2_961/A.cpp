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
int n, k;

void solve() {
    cin >> n >> k;
    if (n == 1) {
        if (k == 0) {
            cout << 0 << el;
            return;
        } else
            cout << 1 << el;
        return;
    }
    int sum = 0;
    int len = n;
    while (k > 0) {
        if (len == n) {
            if (k >= n) {
                k -= n;
                sum++;
            }
            len--;
        } else {
            if (k >= 2 * len) {
                k -= 2 * len;
                sum += 2;
                len--;
            } else if (len < k and k < 2 * len) {
                sum += 2;
                k = 0;
                break;
            } else {
                sum += 1;
                k = 0;
                break;
            }
        }
    }
    cout << sum << el;
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
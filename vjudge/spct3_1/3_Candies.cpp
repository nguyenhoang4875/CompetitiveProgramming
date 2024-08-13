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
int n;

void solve() {
    cin >> n;
    if (n <= 10) {
        cout << 1 << el;
        return;
    }

    auto check = [&](int k) {
        int sum = k;
        int tn = n - k;
        while (tn >= 10) {
            tn -= tn / 10;
            if (tn >= k) {
                tn -= k;
                sum += k;
            } else {
                break;
            }
            if (sum >= (n + 1) / 2) return true;
        }
        sum += tn;
        return sum >= (n + 1) / 2;
    };
    int ans = n;
    int l = 1, r = (n + 1) / 2;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
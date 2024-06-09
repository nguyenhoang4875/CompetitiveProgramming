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
int b, n;

void solve() {
    while (true) {
        cin >> b >> n;
        if (!b and !n) return;
        vii a(n);
        for (auto& e : a) {
            // first: money, second: fun
            cin >> e.F >> e.S;
        }

        vi f(b + 5, 0);
        for (int i = 0; i < n; i++) {
            for (int j = b; j >= 0; j--) {
                int money = a[i].F;
                int fun = a[i].S;
                if (j >= money) {
                    f[j] = max(f[j], f[j - money] + fun);
                }
            }
        }
        int maxFun = f[b];
        int minMoney = 0;
        for (int i = b; i >= 0; i--) {
            if (f[i] < maxFun) {
                minMoney = i + 1;
                break;
            }
        }
        cout << minMoney << " " << maxFun << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
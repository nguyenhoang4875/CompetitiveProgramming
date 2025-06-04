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
    int ans = 0;
    while (k >= 0) {
        int ret = 1;
        for (int i = 0; i < k; i++) ret *= (n - i);
        for (int i = 1; i <= k; i++) ret /= i;

        if (k == 0) ret *= 1;
        if (k == 1) ret *= 0;
        if (k == 2) ret *= 1;
        if (k == 3) ret *= 2;
        if (k == 4) ret *= 9;
        ans += ret;
        k--;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
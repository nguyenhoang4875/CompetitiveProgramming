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
int n;

void solve() {
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << 0 << el;
        return;
    }
    sum /= 2;
    vvi f(n + 1, vi(sum + 5, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            f[i][j] += f[i - 1][j];
            if (j >= i) {
                f[i][j] += f[i - 1][j - i];
            }
            f[i][j] %= mod;
        }
    }
    /*
    Additionally, we could double count every single set. So, instead of counting up to N,
    we'll count up until N - 1, ensuring that the $N$ th element is always placed in the second set
    */
    cout << f[n - 1][sum] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
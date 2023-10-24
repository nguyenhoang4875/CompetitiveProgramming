#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
int n;

void solve() {
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (n % 4 == 0) {
        cout << n / 2 << '\n';
        for (int i = 1; i <= n / 4; i++) {
            cout << i << " " << n + 1 - i << ' ';
        }
        cout << '\n';
        cout << n / 2 << '\n';
        for (int i = n / 4 + 1; i <= n / 2; i++) {
            cout << i << " " << n + 1 - i << ' ';
        }
        return;
    }
    int cnt = n / 2;
    cout << cnt << '\n';
    For(i, 1, cnt / 2) { cout << i << " " << n - i << " "; }
    cout << n << '\n';
    cout << n - cnt << "\n";
    For(i, cnt / 2 + 1, cnt) { cout << i << " " << n - i << " "; }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
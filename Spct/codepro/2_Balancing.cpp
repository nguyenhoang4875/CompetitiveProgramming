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
const int ms = 150 + 5;
int a[ms][ms];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    int tong = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int hang = 0;
        for (int j = 1; j <= n; j++) {
            tong += a[i][j];
            hang += a[i][j];
        }
        mx = max(mx, hang);
        int cot = 0;
        for (int j = 1; j <= n; j++) {
            cot += a[j][i];
        }
        mx = max(mx, cot);
    }
    cout << mx * n - tong << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
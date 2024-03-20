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
const int ms = 30 + 5;
int n, m;
char a[ms][ms], b[ms][ms];

void solve() {
    cin >> n >> m;
    For(i, 0, n - 1) {
        For(j, 0, m - 1) { cin >> a[i][j]; }
    }
    For(i, 0, n - 1) {
        For(j, 0, m - 1) { cin >> b[i][j]; }
    }

    For(s, 0, n - 1) {
        For(t, 0, m - 1) {
            bool ok = true;
            For(i, 0, n - 1) {
                For(j, 0, m - 1) {
                    int ni = (i + s) % n;
                    int nj = (j + t) % m;
                    if (a[ni][nj] != b[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) {
                cout << "Yes" << el;
                return;
            }
        }
    }
    cout << "No" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
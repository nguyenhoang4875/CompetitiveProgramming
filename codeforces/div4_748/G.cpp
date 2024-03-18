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
const int ms = 50 + 5;
int n, m;
char a[ms][ms];

void solve() {
    cin >> n >> m;
    For(i, 1, n) {
        For(j, 1, m) { cin >> a[i][j]; }
    }
    For(t, 1, n) {
        Ford(i, n, 2) {
            For(j, 1, m) {
                if (a[i][j] == '.' and a[i - 1][j] == '*') {
                    a[i][j] = '*';
                    a[i - 1][j] = '.';
                }
            }
        }
    }
    For(i, 1, n) {
        For(j, 1, m) { cout << a[i][j]; }
        cout << el;
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
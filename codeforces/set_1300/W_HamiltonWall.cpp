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
const int ms = 1e5 + 5;
int n;

void solve() {
    cin >> n;
    vvc v(2, vc(n));

    For(i, 0, 1) {
        For(j, 0, n - 1) {
            cin >> v[i][j];
        }
    }

    bool row1 = true, row2 = true;

    For(i, 0, n - 1) {
        if(v[0][i] == 'B' and v[1][i] == 'B') {
            swap(row1, row2);
        } else if(v[0][i] == 'B') {
            row2 = false;
        } else if(v[1][i] == 'B') {
            row1 = false;
        } 
    }
    if(row1 || row2) {
        cout << "YES\n";
    } else cout << "NO\n";

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
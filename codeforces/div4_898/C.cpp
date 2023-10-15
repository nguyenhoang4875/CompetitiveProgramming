#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 15;
int n = 10;
char a[ms][ms];

int getPoint(int r, int c) {
    int point = oo;
    point = min(point, min(r, n - r + 1));
    point = min(point, min(c, n - c + 1));
    return point;
}

void solve() {
    For(i, 1, n) {
        For(j, 1, n) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    For(i, 1, n) {
        For(j, 1, n) {
            if(a[i][j] == 'X') {
                sum += getPoint(i, j);
            }
        }
    }
    cout << sum << '\n';

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
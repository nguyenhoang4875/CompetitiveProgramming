#include <bits/stdc++.h>
#define int long long
#define pb push_back

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
const int ms = 505;
int n, m, k;
char a[ms][ms];

int ans = oo;

void cal() {
    for(int i = 1; i <= n - k + 1; i++) {
        for(int j = 1 ; j <= m - k + 1; j++) {
            int xm = i + (k - 1) / 2;
            int ym = j + (k - 1) / 2;
            int sum1 = 0;
            int sum2 = 0;
            for(int r = i; r <= k + i - 1; r++) {
                for(int c = j; c <= k + j - 1; c++) {
                    if(a[r][c] == '1') {
                        sum1 += abs(r - xm) + abs(c - ym);
                    }
                    if(a[r][c] == '2') {
                        sum2 += abs(r - xm) + abs(c - ym);
                    }

                }
            }
            // cout << i << " " <<  j << endl;
            // cout << sum1 << " " <<  sum2 << endl;
            ans = min(ans, abs(sum1 - sum2));
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cal();
    cout << ans << '\n';


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
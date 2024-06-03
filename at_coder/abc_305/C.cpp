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
const int ms = 5e2 + 5;
int n, m;
char a[ms][ms];

void solve() {
    cin >> n >> m;
    int xMin = oo, yMin = oo, xMax = 0, yMax = 0;
    For(i, 1, n) {
        For(j, 1, m) {
            cin >> a[i][j];
            if(a[i][j] == '#') {
                xMin = min(xMin, i);
                xMax= max(xMax, i);
                yMin = min(yMin, j);
                yMax = max(yMax, j);;
            }
        }
    }
    For(i, xMin, xMax) {
        For(j, yMin, yMax) {
            if(a[i][j] != '#') {
                cout << i << " " << j << el;
                return;
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

#define el '\n'

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 405;

int powerMod(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

int gauss(int nVar, vector<bitset<ms>>& f) {
    int row = 0;
    int m = f.size();  // number equation
    for (int col = 0; col < nVar and row < m; ++col) {
        int sel = -1;
        for (int i = row; i < m; ++i) {
            if (f[i][col]) {
                sel = i;
                break;
            }
        }
        if (sel == -1) continue;  // not found any variable need to fix
        swap(f[sel], f[row]);     // move this sel top top did not review

        for (int i = 0; i < m; ++i) {
            if (i != row and f[i][col]) f[i] ^= f[row];  // fix variable col in row i
        }
        ++row;
    }

    for (int i = row; i < m; i++) {
        if (f[i][nVar]) return -1;
    }
    return nVar - row;
};

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> varPos;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    int cntVar = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == '?') varPos[{i, j}] = cntVar++;
        }
    }
    vector<bitset<ms>> f;
    for (int i = 1; i <= n; i++) {
        bitset<ms> row;
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '1') sum ^= 1;
            else if (a[i][j] == '?') row[varPos[{i, j}]] = 1;
        }
        row[cntVar] = sum;
        f.push_back(row);
    }

    for (int j = 1; j <= n; j++) {
        bitset<ms> col;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == '1') sum ^= 1;
            else if (a[i][j] == '?') col[varPos[{i, j}]] = 1;
        }
        col[cntVar] = sum;
        f.push_back(col);
    }

    int num = gauss(cntVar, f);
    if (num == -1) cout << 0 << el;
    else cout << powerMod(2, num) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
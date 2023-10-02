#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/15705
 * Solution: Brute force: 8 directions
 */

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
const int ms = 105;
int n, m;
string s;
int len;
char a[105][105];
vii dirs = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
            {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

bool check(int r, int c) {
    for (pii dir : dirs) {
        if (dir.first * (len - 1) + r >= 0 && dir.first * (len - 1) + r < n &&
            dir.second * (len - 1) + c >= 0 && dir.second * (len - 1) + c < m) {
            bool isMatched = true;
            for (int i = 1; i < len; i++) {
                if (s[i] != a[dir.first * i + r][dir.second * i + c]) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) return true;
        }
    }
    return false;
}

void solve() {
    cin >> s;
    cin >> n >> m;
    len = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (len > n && len > m) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == s[0]) {
                if (check(i, j)) {
                    cout << "1\n";
                    return;
                }
            }
        }
    }
    cout << "0\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
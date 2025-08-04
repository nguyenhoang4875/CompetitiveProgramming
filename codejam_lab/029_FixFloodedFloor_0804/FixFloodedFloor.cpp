#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

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
const int ms = 2e5 + 5;

void solve() {
    int n = 2, m;
    cin >> m;
    vvc a(n + 1, vc(m + 1));
    For(i, 1, n) For(j, 1, m) cin >> a[i][j];

    vi d(m + 1);
    For(j, 1, m) {
        d[j] = d[j - 1];
        d[j] += (a[1][j] == '.');
        d[j] += (a[2][j] == '.');
    }

    vvb seen(n + 1, vb(m + 1));

    auto inBound = [&](int x, int y) {
        return 1 <= x and x <= n and 1 <= y and y <= m;
    };

    const int dx[4] = {-1, 1, 0, 0};  // need to fill vertical first
    const int dy[4] = {0, 0, -1, 1};

    For(j, 1, m) {  // check for column first
        For(i, 1, n) {
            if (!seen[i][j] and a[i][j] == '.') {
                seen[i][j] = true;
                bool ok = false;
                Rep(k, 4) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (!inBound(nx, ny) or a[nx][ny] == '#' or seen[nx][ny]) continue;
                    seen[nx][ny] = true;
                    ok = true;
                    break;
                }
                if (!ok) {
                    cout << "None" << el;
                    return;
                }
            }
        }
    }

    auto checkSquare = [&](int col) {
        return d[col - 2] % 2 == 0 and d[col] - d[col - 2] == 4;
    };

    bool multi = false;
    For(col, 2, m) {
        if (checkSquare(col)) {
            multi = true;
            break;
        }
    }

    if (multi) cout << "Multiple" << el;
    else cout << "Unique" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
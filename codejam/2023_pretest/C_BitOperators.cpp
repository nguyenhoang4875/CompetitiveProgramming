#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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
const int ms = 20;
int n;

int num[ms];
int tree[ms][200000];

void solve() {
    num[0] = 1;
    for (int i = 1; i < ms; i++) num[i] = num[i - 1] * 2;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < num[n]; i++) cin >> tree[n][i];

    int type = n % 2;

    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < num[i]; j++)
            if (i % 2 == type)
                tree[i][j] = tree[i + 1][j * 2] ^ tree[i + 1][j * 2 + 1];
            else
                tree[i][j] = tree[i + 1][j * 2] | tree[i + 1][j * 2 + 1];

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;

        tree[n][p - 1] = b;
        int pos = p - 1;
        for (int j = n - 1; j >= 0; j--) {
            pos = pos / 2;
            if (j % 2 == type)
                tree[j][pos] = tree[j + 1][pos * 2] ^ tree[j + 1][pos * 2 + 1];
            else
                tree[j][pos] = tree[j + 1][pos * 2] | tree[j + 1][pos * 2 + 1];
        }

        cout << tree[0][0] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, q;

void solve() {
    cin >> n >> q;
    vi row(n, 0), col(n, 0);
    vi timeRow(n, -1), timeCol(n, -1);

    int type, idx, val;
    for (int i = 0; i < q; i++) {
        cin >> type >> idx >> val;

        if (type == 0) {
            // row
            timeRow[idx] = i;
            row[idx] = val;
        } else {
            timeCol[idx] = i;
            col[idx] = val;
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (timeRow[i] > timeCol[j]) {
                sum += row[i];
            } else {
                sum += col[j];
            }
        }
    }
    cout << sum << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
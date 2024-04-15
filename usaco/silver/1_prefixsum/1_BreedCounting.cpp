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
    vi c1(n + 1, 0);
    vi c2(n + 1, 0);
    vi c3(n + 1, 0);
    For(i, 1, n) {
        int x;
        cin >> x;
        c1[i] = c1[i - 1];
        c2[i] = c2[i - 1];
        c3[i] = c3[i - 1];

        if (x == 1) c1[i]++;
        if (x == 2) c2[i]++;
        if (x == 3) c3[i]++;
    }

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << c1[r] - c1[l - 1] << " ";
        cout << c2[r] - c2[l - 1] << " ";
        cout << c3[r] - c3[l - 1] << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    solve();
    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n;
int a[ms], b[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    vi pa(n + 1, 0);
    vi pb(n + 1, 0);
    For(i, 1, n) {
        pa[i] = pa[i - 1];
        if (a[i] == 1) pa[i]++;

        pb[i] = pb[i - 1];
        if (b[i] == 1) pb[i]++;
    }

    int sa = 0, sb = 0;
    Rof(i, n, 1) {
        if (a[i] == b[i]) {
            if(a[i] == 0) {
                continue;
            }
            if(a[i] == 1) {
                if(sa + pa[i - 1] <= sb + pb[i - 1]) sa += 1;
                else sb += 1;

            } else {
                if(sa + pa[i - 1] <= sb + pb[i - 1]) sb -= 1;
                else sa -= 1;
            }

        } else if (a[i] > b[i]) {
            sa += a[i];
        } else {
            sb += b[i];
        }
        // cout << sa << " " << sb << el;
    }
    cout << min(sa, sb) << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
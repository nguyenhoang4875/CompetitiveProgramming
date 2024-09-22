#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
    int n, d, k;
    cin >> n >> d >> k;
    vi vl(n + 1), vr(n + 2);
    // vl number job was started from i sofar
    // vr number job was end from i sofar
    // ans = vl[i] - vr[i - d]
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        vl[l]++;
        vr[r]++;
    }

    for (int i = 1; i <= n; i++) vl[i] += vl[i - 1];
    for (int i = 1; i <= n; i++) vr[i] += vr[i - 1];

    int imn, imx;
    int valMin = oo, valMax = -1;
    for (int i = d; i <= n; i++) {
        int val = vl[i] - vr[i - d];
        if (val < valMin) {
            valMin = val;
            imn = i - d + 1;
        }
        if (val > valMax) {
            valMax = val;
            imx = i - d + 1;
        }
    }
    cout << imx << " " << imn << el;
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
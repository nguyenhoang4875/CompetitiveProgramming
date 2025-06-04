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
const int ms = 3e5 + 5;
int n, q;
int a[ms];
int preSum[ms];
int cnt1[ms];

void solve() {
    cin >> n >> q;
    For(i, 1, n) {
        cin >> a[i];
        preSum[i] = a[i] + preSum[i - 1];
        cnt1[i] = cnt1[i - 1];
        if(a[i] == 1) cnt1[i]++;
    }

    int l, r;
    while(q--) {
        cin >> l >> r;
        if(l == r) {
            cout << "NO" << el;
            continue;
        }
        int sum = preSum[r] - preSum[l - 1];
        int c1 = cnt1[r] - cnt1[l - 1];
        int len = r - l + 1;
        if(sum < len + c1) {
            cout << "NO" << el;
        } else {
            cout << "YES" << el;
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
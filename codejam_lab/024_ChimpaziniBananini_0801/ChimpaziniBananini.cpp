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
    int q;
    cin >> q;
    deque<int> dq;

    int ans = 0, sum = 0, l2r = 1;
    int n = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int val = 0;
            if (l2r) {
                val = dq.back();
                dq.pop_back();
                dq.push_front(val);
            } else {
                val = dq.front();
                dq.pop_front();
                dq.push_back(val);
            }
            ans += sum - n * val;
        } else if (op == 2) {
            l2r ^= 1;
            ans = (n + 1) * sum - ans;
        } else {
            n++;
            int k;
            cin >> k;
            sum += k;
            ans += k * n;
            if (l2r) dq.push_back(k);
            else dq.push_front(k);
        }
        cout << ans << el;
    }
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
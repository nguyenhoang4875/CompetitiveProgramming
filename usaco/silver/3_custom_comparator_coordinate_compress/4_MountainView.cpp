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
int n;

bool cmp(pii& p1, pii& p2) {
    if (p1.F == p2.F) p1.S > p2.S;
    return p1.F < p2.F;
}

void solve() {
    cin >> n;
    vii vm(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vm[i] = {x - y, x + y};
    }

    sort(all(vm), cmp);
    int cnt = 0;
    int curEnd = -1;
    for (int i = 0; i < n; i++) {
        if (curEnd < vm[i].S) {
            cnt++;
            curEnd = vm[i].S;
        }
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
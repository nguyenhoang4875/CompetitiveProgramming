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
const int ms = 1e5 + 5;
string s;
int n, k;

void solve() {
    cin >> s;
    cin >> k;
    n = sz(s);
    if(n < k) {
        cout << "impossible" << el;
        return;
    }

    vi cnt(26);
    For(i, 0, n - 1) {
        cnt[s[i] - 'a']++;
    }
    int cntHave = 0;
    For(i, 0 , 25) {
        if(cnt[i]) cntHave++;
    }
    if(cntHave <= k) {
        cout << k - cntHave << el;
        return;
    }
    sort(all(cnt));
    int rm = cntHave - k;
    int ans = 0;
    for(auto e: cnt) {
        if(e == 0) continue;
        ans += e;
        rm--;
        if(rm == 0) break;
    }
    cout << ans << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
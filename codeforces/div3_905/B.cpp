#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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
int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    int cnt[30] = {};
    For(i, 0, n - 1) {
        cnt[s[i] - 'a']++;
    }

    int cntOdd = 0;
    For(i, 0, 25) {
        if(cnt[i] & 1) cntOdd++;
    }
    if(cntOdd > k + 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
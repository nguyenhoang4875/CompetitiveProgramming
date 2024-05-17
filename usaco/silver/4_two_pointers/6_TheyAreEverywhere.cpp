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
string s;

void solve() {
    cin >> n >> s;
    set<char> sc;
    for (auto c : s) sc.insert(c);
    int total = sc.size();

    int l = 0, r = 0;
    map<char, int> m;
    int cnt = 0;
    int ans = oo;
    while (r < n) {
        if (!m.count(s[r]) or m[s[r]] == 0) {
            cnt++;
        }
        m[s[r]]++;
        while (cnt == total) {
            ans = min(ans, r - l + 1);
            m[s[l]]--;
            if (m[s[l]] == 0) {
                cnt--;
            }
            l++;
        }
        r++;
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
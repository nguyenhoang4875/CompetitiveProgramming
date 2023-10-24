#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using namespace std;

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
int n;

int cnt[30];

void solve() {
    string s;
    cin >> s;
    n = s.size();
    For(i, 0, n - 1) { cnt[s[i] - 'A']++; }
    int odd = 0;
    int idx = 0;
    For(i, 0, 25) {
        if (cnt[i] & 1) {
            odd++;
            idx = i;
        }
    }
    if (odd > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    string p1 = "";
    For(i, 0, 25) {
        if (cnt[i] == 0) continue;
        For(j, 0, cnt[i] / 2 - 1) {
            char c = i + 'A';
            p1 += c;
        }
    }
    string p2 = p1;
    reverse(p2.begin(), p2.end());
    if (odd == 1) {
        cout << (p1 + char(idx + 'A') + p2) << "\n";
    } else {
        cout << p1 + p2 << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
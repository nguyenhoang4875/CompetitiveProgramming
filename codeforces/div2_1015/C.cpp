#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    vector<bool> used(n + 1, false);
    vector<pair<int, int>> mirrors;
    int sameIdx = -1;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        if (a[i] == b[i]) {
            if (n % 2 == 0 || sameIdx != -1) {
                ok = false;
                break;
            }
            sameIdx = i;
            used[i] = true;
        } else {
            int foundIdx = -1;
            for (int j = i + 1; j <= n; j++) {
                if (!used[j] and a[j] == b[i] and b[j] == a[i]) {
                    foundIdx = j;
                    break;
                }
            }
            if (foundIdx == -1) {
                ok = false;
                break;
            }
            used[i] = used[foundIdx] = true;
            mirrors.push_back({min(i, foundIdx), max(i, foundIdx)});
        }
    }
    if (n % 2 == 0) {
        if (sameIdx != -1 || (int)mirrors.size() != n / 2) ok = false;
    } else {
        if (sameIdx == -1 || (int)mirrors.size() != (n - 1) / 2) ok = false;
    }
    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    vector<int> target(n + 1, 0);
    int left = 1, right = n;
    for (auto& p : mirrors) {
        target[p.first] = left;
        target[p.second] = right;
        left++;
        right--;
    }
    if (sameIdx != -1) target[sameIdx] = (n + 1) / 2;
    vector<int> Q(n + 1, 0);
    for (int i = 1; i <= n; i++) Q[target[i]] = i;
    vector<int> R(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        R[i] = i;
        pos[i] = i;
    }
    vector<pair<int, int>> ops;
    for (int p = 1; p <= n; p++) {
        if (R[p] == Q[p]) continue;
        int x = Q[p], curPos = pos[x];
        ops.push_back({p, curPos});
        swap(R[p], R[curPos]);
        pos[R[p]] = p;
        pos[R[curPos]] = curPos;
    }
    cout << ops.size() << "\n";
    for (auto& op : ops) cout << op.first << " " << op.second << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}
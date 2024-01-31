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

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

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
const int ms = 2e5 + 5;

void solve() {
    int n, currentCash, cost, profitGoal;
    cin >> n >> currentCash >> cost >> profitGoal;

    vi profit(n + 1, 0);
    For(i, 1, n) {
        cin >> profit[i];
        profit[i] -= cost;

        // making  cumulative
        profit[i] += profit[i - 1];
    }

    deque<int> dq;
    int maxIdx = -1, minLen = oo;

    For(i, 0, n) {
        while (!dq.empty() and profit[i] < profit[dq.back()]) dq.pop_back();

        while (!dq.empty() and profit[i] >= profit[dq.front()] + profitGoal) {
            int l = dq.front();
            int len = dq.back() - dq.front() + 1;
            // take range: [l + 1, r]
            if (minLen > len) {
                minLen = len;
                maxIdx = l + 1;
            } else if (minLen == len) {
                maxIdx = max(maxIdx, l + 1);
            }
            dq.pop_front();
        }
        dq.pb(i);
    }
    if (maxIdx == -1 or currentCash < minLen * cost) {
        cout << -1 << el;
    } else {
        cout << maxIdx << " " << maxIdx + minLen - 1 << el;
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
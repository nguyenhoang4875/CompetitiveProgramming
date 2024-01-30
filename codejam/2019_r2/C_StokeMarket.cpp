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
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}
#endif

template<typename T>
void check_here(T x){
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

    int canHave = cost ? currentCash / cost : n;
    vi profit(n + 1, 0);
    For(i, 1, n) {
        cin >> profit[i];
        profit[i] -= cost;

        // making  cumulative
        profit[i] += profit[i - 1];
    }

    deque<int> dq;
    pii best = {n + 1, 0};

    For(i, 0, n) {
        debug(dq);
        while (!dq.empty() and profit[i] < profit[dq.back()]) dq.pop_back();

        while (!dq.empty() and profit[i] >= profit[dq.front()] + profitGoal) {
            int l = dq.front();
            debug(l);
            dq.pop_front();
            best = min(best, pii(i - l, -l));
            debug(best);
        }
        dq.pb(i);
    }
    if (best.F > canHave) {
        cout << -1 << el;
    } else {
        cout << -best.S + 1 << " " << -best.S + best.F << el;
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
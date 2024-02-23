#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
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
template <class key, class cmp = less<key>>
using ordered_set =
    tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    ordered_set<int, greater<int>> s;
    cin >> n;
    int cnt = 0;
    int x;
    For(i, 1, n) {
        cin >> x;
        s.insert(x);
        cnt += s.order_of_key(x);
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) solve();
    return 0;
}
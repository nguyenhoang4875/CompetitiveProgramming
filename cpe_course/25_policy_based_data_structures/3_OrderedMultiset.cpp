#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace std;
using namespace __gnu_pbds;

template <class key, class cmp = less<pair<key, int>>>
using ordered_multiset = tree<pair<key, int>, null_type, cmp, rb_tree_tag,
                              tree_order_statistics_node_update>;

void solve() {
    ordered_multiset<int> s;
    int t = 0;
    s.insert({1, t++});
    s.insert({1, t++});
    s.insert({2, t++});
    s.insert({2, t++});
    s.insert({3, t++});
    s.insert({7, t++});
    for (int i = 0; i < s.size(); i++) {
        cout << i << ": " << s.find_by_order(i)->first << '\n';
    }

    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << i << ": " << s.order_of_key({i, 0}) << "\n";
    }

    cout << endl;

    s.erase(s.lower_bound({1, 0}));
    // use s.lower_bound({x, 0}) to erase x
    for (auto e : s) {
        cout << e.first << " " << e.second << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
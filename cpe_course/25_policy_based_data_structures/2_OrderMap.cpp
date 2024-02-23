#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace std;
using namespace __gnu_pbds;

template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

ordered_map<int, int> my_map;

void solve() {
    ordered_map<int, int> m;
    m.insert({1, 1});
    m.insert({2, 1});
    cout << m.find_by_order(0)->first << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
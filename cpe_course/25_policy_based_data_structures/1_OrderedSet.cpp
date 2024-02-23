#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace std;
using namespace __gnu_pbds;
template <class key, class cmp = less<key>>
using ordered_set =
    tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    ordered_set<int> s;
    s.insert(3);
    s.insert(6);
    s.insert(10);
    s.insert(1);
    s.insert(7);

    for (int i = 0; i < s.size(); i++) {
        cout << i << ": " << *s.find_by_order(i) << '\n';
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout << i << ": " << s.order_of_key(i) << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
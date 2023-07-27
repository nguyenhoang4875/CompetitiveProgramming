#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codeforces.com/contest/416/problem/C
 * Solution: Brute force for each table, choose the best group for each
 * TC: O(n * k)
 * MC: O(n)
*/


using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, k;

struct node{
    int id, x, y;
}; 

void solve() {
    cin >> n;
    vector<node> v(n);
    int c, p;
    for(int i = 0; i < n; i++) {
        cin >> c >> p;
        v[i] = {i + 1, c, p};
    }

    sort(v.begin(), v.end(), [&](node p1, node p2) {
        return p1.x < p2.x;
    });

    cin >> k;
    vector<pii> vt(k);
    int r;
    for(int i = 0; i < k; i++) {
        cin >> r;
        vt[i] = {i + 1, r};
    }
    sort(vt.begin(), vt.end(), [&](pii p1, pii p2) {
        return p1.second < p2.second;
    });

    int mx = 0;
    int total = 0;
    vector<pii> ans;
    int id = 0;
    vb visited(n + 1);
    for(auto et: vt) {
        mx = -1;
        for(auto e: v) {
            if(et.second >= e.x) {
                if(mx < e.y && !visited[e.id]) {
                    mx = e.y;
                    id = e.id;
                }
            }
        }
        if(mx == -1) continue;
        visited[id] = true; // mark if the table is choose
        total += mx;
        ans.pb({id, et.first});
    }

    cout << ans.size() << " " << total << '\n';
    for(auto e: ans) {
        cout << e.first << " " << e.second << '\n';
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
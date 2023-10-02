#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * #1 the diameter pass through vertex
 * #2 the diameter not pass through vertex
 * 
 * #3 g(cur) length of (cur) to any leaf node in its subtree
 * 
 * 
 * f(cur) = 2 + max1 + max2
 * f(cur) = max(f(x))
 * 
 * 
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int MS = 2e5 + 5;
vi gr[MS];
int f[MS], g[MS];


void dfs(int cur, int par) {
    int max1 = 0, max2 = 0;

    for(auto x: gr[cur]) {
        if(x != par) {
            dfs(x, cur);

            // g for the cur node
            g[cur] = max(g[x] + 1, g[cur]);
            f[cur] = max(f[x], f[cur]);

            // max 2 values of g[x]
            if(g[x] + 1 > max1) {
                max2 = max1;
                max1 = g[x] + 1;
            } else if(g[x] + 1 > max2) {
                max2 = g[x] + 1;
            }
        }
    }
    f[cur] = max(f[cur], max1 + max2);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].pb(y);
        gr[y].pb(x);
    }

    dfs(1, -1);
    cout << f[1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();
    return 0;
}
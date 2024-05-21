#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://cses.fi/problemset/task/1132
 * Solution: DP on Tree
 *
 * TC: O(n)
 * MC: O(n)
 */

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
vi gr[ms];
int f[ms], g[ms];

/*
f[cur] the diameter of the subtree of cur
g[cur] the max length of cur  to any leaf node in its subtree (max depth)

f[x] = max(f[x], max1 + max2)
max1, and max2 is first and second max depth from cur node
*/

void dfsG(int cur, int par) {
    for (auto child : gr[cur]) {
        if (child != par) {
            dfsG(child, cur);
            g[cur] = max(g[cur], g[child] + 1);
        }
    }
}

void dfsF(int cur, int par, int disPar) {
    int max1 = -1, max2 = -1;
    for (auto child : gr[cur]) {
        if (child != par) {
            if (g[child] > max1) {
                max2 = max1;
                max1 = g[child];
            } else if (g[child] > max2) {
                max2 = g[child];
            }
        }
    }
    for (auto child : gr[cur]) {
        if (child != par) {
            int newDisPar = disPar;

            // for(auto y: gr[cur]) {
            //     if(y != par && y != child) {
            //         newDisPar = max(g[y], newDisPar);
            //     }
            // }

            if (g[child] == max1) {
                newDisPar = max(newDisPar, max2);
            } else {
                newDisPar = max(newDisPar, max1);
            }
            dfsF(child, cur, newDisPar + 1);

            // for any node in subtree
            f[cur] = max(f[cur], g[child] + 1);
        }
    }
    // for any node in the super tree
    // super tree == compliment of subtree
    f[cur] = max(f[cur], disPar + 1);
}

void solve() {
    cin >> n;
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    // O(n)
    dfsG(1, -1);  // choose root is 1

    // O(n)
    dfsF(1, -1, -1);
    For(i, 1, n) {
        cout << f[i] << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
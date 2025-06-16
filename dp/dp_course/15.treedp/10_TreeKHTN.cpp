#include <bits/stdc++.h>
#define int long long

/*
Cho một đồ thị vô hướng gồm n đỉnh và n − 1 cạnh thỏa mãn với mọi cặp đỉnh u, v của đồ thị tồn tại ít
nhất 1 đường đi từ u đến v, các đỉnh được đánh số từ 1 đến n. Định nghĩa một thành phần liên thông
gồm m đỉnh v1, ..., vm là một tập hợp các đỉnh thỏa mãn:
Với mọi cặp (i, j), tồn tại ít nhất một đường đi từ vi đến vj mà không đi qua bất kỳ đỉnh nào không
thuộc tập v.
Cho một dãy a có n phần tử (các phần tử đánh số từ 1 đến n). Gọi độ đẹp của một thành phần liên
thông gồm m đỉnh v1, ..., vm là av1 + av2 + ... + avm. Tìm độ đẹp lớn nhất của một thành phần liên thông
gồm k đỉnh trên đồ thị đã cho ở trên với mọi k từ 1 đến n.
Input
Dòng đầu tiên gồm 1 số nguyên dương n (1 ≤ n ≤ 5000).
Dòng thứ 2 gồm n số nguyên dương lần lượt là a1, ..., an, các số tách nhau bởi một dấu cách
(−104 ≤ ai ≤ 104 với mọi i từ 1 đến n).
n − 1 dòng tiếp theo, dòng thứ i gồm 2 số nguyên dương ui

, vi (1 ≤ ui

, vi ≤ n) biểu thị cho cạnh thứ i

của đồ thị.
Output
In ra n số d1, ..., dn trên cùng một dòng, trong đó dk là thành phần liên thông gồm k đỉnh có độ đẹp lớn
nhất, các số tách nhau bới một dấu cách.
*/
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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
    vi a(n);
    Rep(i, n) cin >> a[i];

    vvi adj(n);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    vvi f(n + 1, vi(n + 1, -oo)); // f[u][k]: max ans with subtree with root i has k vertices
    vi treeSize(n); // treeSize[u]: size of subtree at u

    function<void(int, int)> dfs = [&](int u, int par) {
        f[u][1] = a[u];
        treeSize[u] = 1;

        for(int &v: adj[u]) {
            if(v == par) continue;
            dfs(v, u);

            vi tmp(n + 1, -oo);
            for(int i = 1; i <= treeSize[u]; i++) {
                for(int j = 1; j <= treeSize[v]; j++) {
                    tmp[i + j] = max(tmp[i + j], f[u][i] + f[v][j]);
                }
            }
            treeSize[u] += treeSize[v];

            for(int i = 1; i <= treeSize[u]; i++) {
                f[u][i] = max(f[u][i], tmp[i]);
            }
        }
    };

    dfs(0, - 1);
    for(int k = 1; k <= n ; k++) {
        int ans = -oo;
        for(int root = 0; root < n; root++) {
            ans = max(ans, f[root][k]);
        }
        cout << ans << " ";
    }
    cout << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
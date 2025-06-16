#include <bits/stdc++.h>
#define int long long

/*
Đánh số thứ tự các đỉnh theo thứ tự thăm DFS nghĩa là: ta duyệt cây bằng thuật toán DFS,
đỉnh thăm đầu tiên được đánh số 1, đỉnh thăm tiếp theo đánh số 2, ... n đánh số n.

Tính chất quan trọng:
Với mọi đỉnh u trên cây, các số thứ tự của các đỉnh trong cây con gốc u là các số liên tiếp nhau.
Trong cây gốc u, đỉnh u là đỉnh được thăm đầu tiên. Do đó, stt của đỉnh u là nhỏ nhất trong cây con gốc u.
Do đó ta sẽ tính 2 mảng tin[1..n], tout[1..n] với ý nghĩa:
    tin[u] = số thứ tự nhỏ nhất của 1 đỉnh trong cây con gốc u (chính là stt của đỉnh u)
    tout[u] = số thứ tự lớn nhất của 1 đỉnh trong cây con gốc u.

Tính chất:
Đỉnh u là tổ tiên của đỉnh v (nói cách khác, v thuộc cây con gốc u) khi và chỉ khi:
    tin[u] <= tin[v] <= tout[u]
Đỉnh v không thuộc cây con gố u khi 1 trong 2 được thỏa mãn:
    tin[v] < tin[u]
    tin[v] > tout[u]

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
    vvi adj(n);

    vi tin(n + 1), tout(n + 1);
    int cnt = 0;

    function<void(int, int)> dfs = [&] (int u, int par) {
        tin[u] = ++cnt;
        for(auto &v: adj[u]) {
            if(v == par) continue;
            dfs(v, u);
        }
        tout[u] = cnt;
    };

    dfs(1, 0);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
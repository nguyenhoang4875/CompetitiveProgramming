#include <bits/stdc++.h>
#define int long long

/*
Cho một cây gồm n đỉnh, đỉnh i có giá trị là a[i].
Tập S gồm một số đỉnh trên cây được gọi là tập độc lập nếu như với mọi cặp đỉnh (x, y) trong S;
x và y không được nối trực tiếp bởi một cạnh.

Cần tìm tập độc lập S sao cho tổng trọng số các đỉnh trong S là lớn nhất.

Phân tích lời giải:
Nhận xét: mọi cạnh ở trên cây luôn nối giữa một đỉnh u và cha của nó. Vì vậy, ràng buộc "không được đồng thời lấy hai
đỉnh kề nhau" có thể được hiểu là: với mọi cặp cha con, nếu lấy cha thì phải bỏ con, hoặc nếu đã lấy con thì không được
lấy cha của nó.

Gọi F[u, 0] và F[u, 1] lần lượt là tổng giá trị của một tập độc lập lớn nhất bên trong cây con gốc u, trong hai trường
hợp: F[u, 0]: Ta không chọn đỉnh u F[u, 1]: Ta có chọn đỉnh u

Khi tính F[u, 0], ta thấy: Do không chọn đỉnh u, các đỉnh con của u (v1, v2, ..., vk) có thể được chọn. Các cây con gốc
v1 v2 ... vk hoàn toàn độc lập với nhau. Việc chọn đỉnh nào trong cây con gốc v1 hoàn toàn không ảnh hưởng đến việc chọn
các đỉnh trong cây con gốc v2 F[u, 0] = max(F[v1, 0], F[v1, 1]) + max(F[v2, 0], F[v2, 1]) + max(F[v3, 0], F[v3, 1]) +
... +

Với F[u, 1], ta chú ý rằng: Do u đã chọn nên mọi đỉnh v1 v2 ... vk đều phải bỏ đi. Vì vậy, ta có:
        F[u, 1] = a[u] + F[v1, 0] + F[v2, 0] + ... + F[vk, 0]


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
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vvi adj(n + 1);
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    };

    vvi f(n + 1, vi(2, 0));
    function<void(int, int)> dfs = [&](int u, int par) {
        f[u][1] = a[0];
        f[u][0] = 0;
        for (auto &v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);

            f[u][0] += max(f[v][0], f[v][1]);
            f[u][1] += f[v][0];
        }
    };
    dfs(1, -1);
    cout << max(f[1][1], f[1][0]) << el;
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
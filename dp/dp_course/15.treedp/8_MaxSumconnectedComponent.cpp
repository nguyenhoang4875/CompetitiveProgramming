#include <bits/stdc++.h>
#define int long long

/*
Trong ví dụ này, ta đơn giản hóa một chút bài toán như sau:
Cho một cây gồm n đỉnh với giá trị a1 a2 ... an. Tìm ra vùng liên thông có tổng giá trị các đỉnh là lớn nhất.
(tạm bỏ qua yêu cầu vùng liên thông có đúng k đỉnh).
Vùng liên thông trên cây
Tính chất quan trọng: Mọi vùng liên thông trên cây luôn có cấu trúc như sau:
	Chọn một đỉnh u gọi là "gốc" của vùng liên thông
	Các đỉnh còn lại của vùng liên thông bắt buộc phải thuộc cây con gốc u, đồng thời được chọn theo quy tắc: Đỉnh x được chọn thì cha của x cũng phải được chọn
Quy hoạch động trên cây
Gọi F[u] là tổng giá trị lớn nhất của một vùng liên thông có gốc là u. F[u] sẽ được tính bởi các F[v1], F[v2], ..., F[vk] (các con của u) như sau:
	Với mỗi nhánh con (cây con gốc vi), ta có hai sự lựa chọn:
		Không chọn đỉnh vi -> ta phải bỏ toàn bộ cây con gốc vi
		Chọn đỉnh vi và một vùng liên thông có gốc là đỉnh vi

F[u] = a[u] + max(0, F[v1]) + max(0, F[v2]) + ... + max(0, F[vk])

Kết quả bài toán: max(F[1], F[2], ..., F[n])

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

    vi f(n + 1); // f[u]: max of sum if u is choose in the component

    function<void(int, int)> dfs = [&](int u, int par) {
        f[u] = a[u];
        for(auto &v: adj[u]) {
            if(v == par) continue;
            dfs(v, u);
            f[u] += max(f[v], 0LL);
        }
    };
    dfs(1, 0);
    int ans = 0;
    For(i, 1, n) ans = max(ans, f[i]);
    cout << ans << el;

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
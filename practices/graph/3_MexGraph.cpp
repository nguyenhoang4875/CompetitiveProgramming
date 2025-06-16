#include <bits/stdc++.h>
#define int long long

/*
MEXGRAPH
Cho một đồ thị vô hướng gồm n đỉnh và m cạnh, các đỉnh được đánh số từ 1 đến n. Tìm một dãy a có
gồm n số nguyên không âm thỏa mãn điều kiện sau (Các phần tử của dãy a được đánh số từ 1 đến n):
Với mọi u từ 1 đến n, gọi v1, ..., vk là các đỉnh có cạnh nối trực tiếp với u. Ta có
au = MEX([av1 , av2 , ..., avk ]).
Trong đó, MEX của một dãy b là giá trị nguyên không âm nhỏ nhất mà không tồn tại trong dãy b.
Ví dụ: MEX([2, 2, 1]) = 0, MEX([3, 1, 0, 1]) = 2, MEX([0, 3, 1, 2]) = 4.
Nếu không tồn tại bất kỳ dãy a nào thỏa mãn điều kiện trên, in ra −1.

Input
Dòng đầu tiên gồm 2 số nguyên dương n, m (1 ≤ n ≤ 10^5 , 0 ≤ m ≤ min(n * (n−1)/ 2 , 10^5))
lần lượt biểu thị cho số đỉnh và số cạnh của đồ thị.
m dòng sau, dòng thứ i gồm 2 số nguyên dương ui , vi biểu thị cho cạnh thứ i của đồ thị
(1 ≤ ui , vi ≤ n, ui 6= vi).
Output
Nếu như không tồn tại bất kỳ dãy a nào thỏa mãn đề bài đã cho, in ra một dòng duy nhất gồm số −1.
Trong các trường hợp còn lại, in ra n số trên 1 dòng lần lượt là a1, a2, ..., an, các số tách nhau bởi một
dấu cách.
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
    int n, m;
    cin >> n >> m;

    vvi adj(n + 1);
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    auto findMex = [](vi &v) {
        int n = v.size();
        vb seen(n + 1, false);
        for (auto &e : v) {
            if (e < 0 or e > n) continue;
            seen[e] = true;
        }
        For(i, 0, n - 1) if (!seen[i]) return i;
        return n;
    };

    vi a(n + 1, -1);
    For(u, 1, n) {
        vi val;
        for (auto &v : adj[u]) {
            if (a[v] != -1) val.pb(a[v]);
        }
        a[u] = findMex(val);
    }
    For(i, 1, n) cout << a[i] << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
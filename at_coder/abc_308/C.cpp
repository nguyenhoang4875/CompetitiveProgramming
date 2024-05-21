#include <bits/stdc++.h>
#define int long long

using namespace std;

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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

struct node {
    int id, a, b;
};

void solve() {
    cin >> n;
    vector<node> v(n);
    For(i, 0, n - 1) {
        int a, b;
        cin >> a >> b;
        v[i] = {i + 1, a, b};
    }

    sort(all(v), [&](node &n1, node &n2) {
        int r1 = n1.a * (n2.a + n2.b);
        int r2 = n2.a * (n1.a + n1.b);
        
        if (r1 == r2) return n1.id < n2.id;
        return r1 > r2;
    });
    for (auto e : v) {
        cout << e.id << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
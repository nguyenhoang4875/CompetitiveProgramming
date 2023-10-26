#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
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
const int ms = 1e5 + 5;
int n;
vi tree;

int getSum(int idx) {
    int sum = 0;
    while(idx) {
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void update(int n, int idx, int inc) {
    while(idx <= n){
        tree[idx] +=  inc;
        idx += idx & -idx;
    }
}

void solve() {
    cin >> n;
    vi a(n);
    for(auto &x: a) cin >> x;

    vi temp = a;
    sort(all(temp));
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
    }

    tree.resize(n + 1);
    int inv = 0;
    Ford(i, n - 1, 0) {
        inv = getSum(a[i]- 1) - getSum(a[i] - 2);
        cout << inv << " ";
        update(n, a[i], 1);
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
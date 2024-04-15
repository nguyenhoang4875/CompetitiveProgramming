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
const int ms = 1e6 + 5;
int n, k;
int cnt[ms];

void solve() {
    cin >> n >> k;
    int l, r;
    while (k--) {
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }

    For(i, 1, n) { cnt[i] += cnt[i - 1]; }
    sort(cnt + 1, cnt + n + 1);
    int mid = n / 2 + 1;
    cout << cnt[mid] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
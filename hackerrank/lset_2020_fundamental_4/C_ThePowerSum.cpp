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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int x, n;
int cnt = 0;

int countWay(int x, int n, int num) {
    int val = x - (int)pow(num, n);
    if (val == 0) return 1;
    if (val < 0) return 0;

    return countWay(val, n, num + 1) + countWay(x, n, num + 1);
}

int countWay2(int x, int n, int num) {
    if (x == 0) return 1;
    if (x < 0) return 0;

    // include num
    int ans = 0;
    int val = (int)pow(num, n);
    if (x >= val) {
        ans += countWay2(x - val, n, num + 1);
    }
    // exclude num
    ans += countWay(x, n, num + 1);
    return ans;
}

void solve() {
    cin >> x >> n;
    // cout << countWay(x, n, 1) << el;
    cout << countWay2(x, n, 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
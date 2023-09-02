#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/contest/problem/1113/4
 * Solution:
 *  - Gen Monotone number
 *  - Using prefixSum to calculate the sum all of monotone numbers < n
 *  - Using binary search to find monotone of n
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

const int MOD = 1e9 + 7;
const int MAX = 1e18;
int n;
string s;
int cnt = 0;
int sum = 0;
vector<int> vm;
vi vs;  // sum acc

void accVs() {
    vector<int> tt = vm;
    int tSize = tt.size();
    for (int i = 0; i < tSize; i++) {
        tt[i] %= MOD;
    }
    vs.resize(tSize, 0);
    for (int i = 0; i < tt.size(); i++) {
        if (i > 0) {
            vs[i] = vs[i - 1] +
                    (tt[i] - tt[i - 1] - 1 + MOD) % MOD * (tt[i - 1]) % MOD +
                    vm[i] % MOD;
            vs[i] %= MOD;
        }
    }
}

void fun(string ans, int index, bool last) {
    if (index == s.size()) {
        int t = stoll(ans);
        vm.push_back(t);
        return;
    }

    int till = (last ? (s[index] - '0') : 9);
    int start = (index == 0 ? 0 : ans.back() - '0');

    for (int i = start; i <= till; i++) {
        fun(ans + to_string(i), index + 1, (last && (i == till)));
    }
}

void cal(int x) {
    sum = 0;
    s = to_string(x);
    fun("", 0, true);
}

void init(int x) { cal(x); }

int binarySearch(int val) {
    int pos = -1;
    int l = 0, r = vm.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vm[mid] <= val) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pos;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int posStart = binarySearch(n);
    int posEnd = binarySearch(m);
    int sum = 0;
    int curMax = m;

    int p1 = 0, p2 = 0, p3 = 0;
    if (m < vm[posStart + 1]) {
        p1 = (m % MOD - n % MOD + 1 + MOD) % MOD * (vm[posStart] % MOD) % MOD;
        cout << p1 << '\n';
        return;
    } else {
        p1 = (vm[posStart + 1] % MOD - n % MOD + MOD) % MOD *
             (vm[posStart] % MOD) % MOD;
    }
    if (vm[posStart] == n) {
        p1 = 0;
        p2 = (vs[posEnd] - vs[posStart] + vm[posStart] % MOD + MOD) % MOD;

    } else {
        if (posEnd > posStart)
            p2 =
                (vs[posEnd] - vs[posStart + 1] + vm[posStart + 1] % MOD + MOD) %
                MOD;
    }

    if (vm[posEnd] >= vm[posStart + 1])
        p3 =
            (m % MOD - vm[posEnd] % MOD + MOD) % MOD * (vm[posEnd] % MOD) % MOD;

    sum = (p1 + p2 + p3) % MOD;
    cout << sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init(MAX);
    accVs();

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }

    return 0;
}
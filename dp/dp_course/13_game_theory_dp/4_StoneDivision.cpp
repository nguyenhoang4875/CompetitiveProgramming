#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://www.hackerrank.com/challenges/stone-division
 * Solution
 */

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
int n, m;
int s[15];
map<int, bool> memo;

bool giveWL(int n) {
    if (memo.count(n)) return memo[n];
    for (int i = 1; i <= m; i++) {
        if (n % s[i] == 0 && (s[i] % 2 == 0 || giveWL(n / s[i]) == false))
            return memo[n] = true;
    }
    return memo[n] = false;
}
bool giveWL2(int n) {
    if (memo.count(n)) return memo[n];
    for (int i = 1; i <= m; i++) {
        if (n % s[i] == 0 && s[i] % 2 == 0) return memo[n] = true;
    }

    for (int i = 1; i <= m; i++) {
        if (n % s[i] == 0 && giveWL2(n / s[i]) == false) return memo[n] = true;
    }
    return memo[n] = false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> s[i];
    bool win = giveWL(n);
    if (win)
        cout << "First\n";
    else
        cout << "Second\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
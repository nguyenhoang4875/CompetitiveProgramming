#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Array Jumps
 *  Given an array of positive intergers, where each element
 *  represents the max no of steps you can jump forward in the array.
 *  Find the minimum jumps need to reach the final index
 * Solution: Using DP
 *
 * TC: O(n)
 * MC: O(n)
 */

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
const int ms = 2e5 + 5;
int n;
int a[ms];
int ans = oo;
vi memo;

// O(n)
int minJump(int s) {
    // base case
    if (s >= n) return 0;

    if (memo[s] != -1) return memo[s];
    int ans = oo;
    for (int i = 1; i <= a[s]; i++) {
        ans = min(ans, 1 + minJump(s + i));
    }
    return memo[s] = ans;
}

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    memo = vector<int>(n + 1, -1);
    cout << minJump(1);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
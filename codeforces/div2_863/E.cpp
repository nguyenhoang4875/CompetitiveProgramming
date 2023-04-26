#include<bits/stdc++.h>
#define int long long
 
using namespace std;
 
int dp[19];
int a[19];
 
int f(int i, bool smaller, bool pos) {
  if (i < 0) {
    return pos;
  }
  if (smaller && pos && dp[i] != -1) {
    return dp[i];
  }
  int ans = 0;
  int lim = smaller ? 9 : a[i];
  for (int d = 0; d <= lim; d++) {
    if (d != 4) ans += f(i - 1, smaller || d < lim, pos || d > 0);
  }
  return smaller && pos ? dp[i] = ans : ans;
}
 
int solve(int x) {
  int n = 0;
  do {
    a[n++] = x % 10;
    x /= 10;
  } while (x > 0);
  return f(n - 1, 0, 0);
}
 
void solve() {
  int k;
  cin >> k;
  int lo = 1, hi = 1e18;
  int ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
//    cerr << mid << endl;
    if (solve(mid) >= k) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << ans << "\n";
}
 
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  memset(dp, -1, sizeof(dp));
  int tt; cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
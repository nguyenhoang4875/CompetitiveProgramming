#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int n,m,k;
int buy[12][102];
int sell[12][102];
int item[12][102];
 
int trade(int u,int v) {
  vector<pair<int,int> > best;
  for (int i = 0; i < m; i++) {
    if (buy[u][i] < sell[v][i]) {
        best.push_back({sell[v][i] - buy[u][i], item[u][i]});
    }
  }
  sort(best.rbegin(),best.rend());
  int rem = k,ans = 0;
  for (int i = 0; i < best.size(); i++) {
    int delta = min(rem,best[i].second);
    ans += delta * best[i].first;
    rem -= delta;
  }
  return ans;
}
 
int32_t main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;  cin >> s;
    for (int j = 0; j < m; j++) {
        cin >> buy[i][j] >> sell[i][j] >> item[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i != j) {
            ans = max(ans, trade(i,j));
        }
    }   
  }
  cout << ans << endl;
  return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
bool ans = false;
bool a[2][100005];
string s[2];

void dfs(int row, int col, int waterLevel) {
    if(s[row][col] == 'X' || col < waterLevel || a[row][col]) return;
    if(col + k >= n) {
        ans = true;
        return;
    }
    a[row][col] = true;
    dfs((row + 1) % 2, col + k, waterLevel + 1); // jump to opposite wall
    dfs(row, col + 1, waterLevel + 1); // climb up
    dfs(row, col - 1, waterLevel + 1); // climb down
}

void solve() {
    cin >> n >> k;
    cin >> s[0];
    cin >> s[1];
    dfs(0, 0, 0);
    if(ans) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
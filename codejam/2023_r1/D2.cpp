#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 250005;

int n, f[MAXN], vis[MAXN];
ll score, ans;

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        score = 0;
        ans = 1e18;
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int j = i;
                while (!vis[j]) {
                    vis[j] = 1;
                    j = f[j];
                }
                score++;
            }
        }

        for (int i = 1; i <= n; i++) {
            int j = f[i];
            ans = min(ans, score - (vis[i] && vis[j]) + (!vis[i] && !vis[j]));
        }

        cout << score << " " << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), pre(n + 1, 0), suf(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = max(pre[i - 1], a[i]);
        }

        suf[n] = a[n];
        for (int i = n - 1; i >= 1; i--) suf[i] = min(suf[i + 1], a[i]);

        vector<int> ans = pre;
        for (int i = n - 1; i >= 1; i--) {
            int l = i + 1, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (suf[mid] < pre[i]) {
                    ans[i] = ans[mid];
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[1010] ,f[1010], pre[1010];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // Bước QHĐ
    fill(f, f + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (a[j] <= a[i] && f[i] < f[j] + 1) {
                f[i] = f[j] + 1;
                pre[i] = j;
            }
    }
    // Tìm t là vị trí cuối cùng của dãy dài nhất
    int t = 1;
    for (int i = 1; i <= n; i++) {
        if (f[i] > f[t]) t = i;

    }
    // In ra dãy con đó
    vector<int> seq;
    while (t) {
        seq.push_back(a[t]);
        t = pre[t];
    }
    for (auto val = seq.rbegin(); val != seq.rend(); val++) {
        cout << (*val) << " ";
    }
        cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
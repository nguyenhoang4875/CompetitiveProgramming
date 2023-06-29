#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[5005];


void solve() {
    cin  >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a+ n + 1);
    int cnt = 0;
    int k;
    for (int i = 1; i < n - 1; i++) {
        k = i + 2;
        for (int j = i + 1; j < n ; j++) {
                while(k <= n && a[k] < a[i] + a[j]) k++;
                --k;
                cnt += k - j;
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
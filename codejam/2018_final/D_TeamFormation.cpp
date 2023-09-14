#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int MS = 1e5 + 1;
int n;
int a[MS];

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        int t = a[i];
        cnt++;
        while(i <= n  && t > 1) {
            i++;
            t--;
        }
    }
    cout << cnt << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
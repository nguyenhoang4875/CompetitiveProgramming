#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[5005];

int binary_max(int val) {
    int l = 1;
    int r = n; 
    int pos = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] < 2 * val) {
            pos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return pos;
}

void solve() {
    cin  >> n;
    map<int, int> mi;
    for (int i = 1; i <= n; i++) cin >> a[i], mi[a[i]]++; 
    sort(a + 1, a+ n + 1);
    int cnt = 0;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n ; j++) {
            if(a[i] == a[j]) {
                int pmax = binary_max(a[i]);
                cnt += pmax - mi[a[i]];
              }
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
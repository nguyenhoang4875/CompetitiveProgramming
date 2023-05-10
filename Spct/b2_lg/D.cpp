#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;

int binary_search(int row, int val) {
    int l = 1;
    int r = m;
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int x = row * row + mid * mid;
        if(x <= val) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

 int check(int val) {
    int cnt = 0;
    for (int r = 1; r <= n; r++) {
        cnt += binary_search(r, val);
    }
    return cnt;
}

void solve() {
    cin >> n >> m >> k;
    // swap if m > n
    if(n > m) {
        int temp = n;
        n = m;
        m = temp;
    }
    int ans = 0;
    int l = 1;
    int r = n*n + m*m;
    // tim so nho nhat co so luong so nho hon hoac bang no phai lon hon k
    while(l <= r) {
        int mid = l + (r - l) / 2;
        int cnt = check(mid);
        if(cnt >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
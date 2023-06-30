#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[200005];
int x, y;
int sum;

int binarySearch(int val) {
    int pos = -1;
    int l = 1;
    int r = n;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] >= val) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return pos;
}

void solve() {
    cin >> n;
    sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    cin >> m;
    while(m--) {
        cin >> x >> y;
        int coin = 0;
        int tempSum = sum;
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        if(pos == n + 1) {
            coin += x - a[n];
            tempSum -= a[n];
            if(tempSum < y) coin += y - tempSum;
        } else if(pos == 1) {
            tempSum -= a[pos];
            if(tempSum < y) coin += y - tempSum;
        } else {
            // case 1 take less then x
            int coin1 = 0, coin2 = 0;
            coin1 += x - a[pos - 1];
            tempSum = sum - a[pos - 1];
            if(tempSum < y) coin1 += y - tempSum;

            // case 2 take equal or greater x
            tempSum = sum;
            tempSum -= a[pos];
            if(tempSum < y) coin2 += y - tempSum;
            coin = min(coin1, coin2);

        }
        cout << coin << '\n';

    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
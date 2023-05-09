#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, x, y;
int a[1000005];
int oo = 1e18;

struct node {
    int l, r, sum;
};

void solve() {
    cin >> n;
    cin >> x >> y;
    for (int i = 1; i <= n ; i++) cin >> a[i];
    int l, r;
    int sum = 0;
    int ans = -oo, al = 0, ar = 0;
    for (int i = 1; i <= n; i++) {
        if(a[i] >= x ) {
            l = i;
            sum = 0;
            int res = -oo;
            int mn = oo; 
            do {
                sum += a[i];
                mn = min(a[i], mn);
                if(sum > res) {
                    r = i;
                    res = sum;
                }
                if(sum < 0) {
                    sum = 0;
                    l = i+1;
                }
                i++;
                if(i > n) break;
            } while (a[i] >= x);
            
            if(mn <= y) {
                if(ans < res) {
                    ans = res;
                    al = l;
                    ar = r;
                }
            }
        }
    }
    cout << ans << endl;
    cout << al << " " << ar << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
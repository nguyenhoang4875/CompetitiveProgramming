#include<bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/contest/1808/problem/A
*/

int tcs, n;
int l, r;

int find(int x) {
    int min_digit = 9;
    int max_digit = 0;
    while(x > 0) {
        int temp = x % 10;
        min_digit = min(min_digit, temp);
        max_digit = max(max_digit, temp);
        x /= 10;
    }
    return max_digit - min_digit;
}

void solve() {
    cin >> l >> r;
    if(r - l <= 100) {
        int res = find(r);
        int ans = r;
        for (int x = r-1; x >= l; x--) {
            int temp = find(x);
            if(temp > res) {
                ans = x;
                res = temp;
                if(res == 9) break;
            }
        }
        cout << ans << endl;
        return;
    }

    int x = r;
    x /= 10;
    if(x % 10 == 9) {
        cout << x*10 << endl;
    } else {
        x /= 10;
        x*= 100;
        x-= 10;
        cout << x << endl;
    }

}

int main() {
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
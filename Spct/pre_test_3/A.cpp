#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[105];
int b[105];
int pos = 0;

void encode(int arr[], int n) {
    bool mask[n] = {false}; // assign all member to false
    bool cont = true;
    int idx = n / 2;
    while(cont) {
        if (!mask[idx]) {
            mask[idx] = true;
            b[idx] = arr[pos];
            pos++;
            continue;
        }
        idx *= 2;
        idx %= n;
        for (int i = 0; i < n; ++i) {
            if (mask[idx]) {
                ++idx;
                idx %= n;
            }
            else {
                cont = true;
                break;
            }
            cont = false;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    encode(a, n);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
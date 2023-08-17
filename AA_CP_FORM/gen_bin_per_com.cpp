#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
int cnt =0;
int g[105];
bool used[105];

// Generate Binary
// TC: O(2^n)
void genBin(int idx) {
    if(idx > n) {
        for(int i = 1; i <= n; i++) {
            cout << g[i] << " ";
        }
        cout << endl;
        cnt++;
        return;
    }
    for(int val = 0; val <= 1; val++) {
        g[idx] = val;
        genBin(idx + 1);
    }
}

// Generate Permutation 
// TC: O(n!)
void genPer(int idx) {
    if(idx > n) {
        for(int i = 1; i <= n; i++) {
            cout << g[i] << " ";
        }
        cout << endl;
        cnt++;
        return;
    }
    for(int val = 1; val <= n; val++) {
        if(used[val]) continue;
        used[val] = true;
        g[idx] = val;
        genPer(idx + 1);
        used[val] = false;
    }
}

// Generate Permutation 
// TC: O(n! / (k! * (n - k)!))
void genCom(int idx) {
    if(idx > k) {
        for(int i = 1; i <= k; i++) {
            cout << g[i] << " ";
        }
        cout << endl;
        cnt++;
        return;
    }
    for(int val = 1; val <= n; val++) {
        if(used[val]) continue;
        if(idx > 1 && g[idx - 1] > val) continue;
        used[val] = true;
        g[idx] = val;
        genCom(idx + 1);
        used[val] = false;
    }
}

void solve() {
    cin >> n >> k;
    cnt = 0;
    // genBin(1);
    // genPer(1);
    genCom(1);
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
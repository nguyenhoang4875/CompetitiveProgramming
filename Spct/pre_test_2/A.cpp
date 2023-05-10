#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<int> a(105);
vector<int> b(105);
int ans = 0;

int get_score(int n, vector<int> &A, vector<int> &B) {
    int res = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] == B[i]) {
            tmp++;
        } else {
            tmp = 0;
        }
        res = max(res, tmp);
    }
    return res;
}

vector<int> delete_at(int pos, vector<int> &A) {
    vector<int> t(105);
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        if(i == pos) {
            continue;
        }
        t[idx++] = A[i];
    }
    return t;
}

void solve() {
     cin >> n; 
     for (int i = 1; i <= n; i++) cin >> a[i];
     for (int i = 1; i <= n; i++) cin >> b[i];

     for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vector<int> aa = delete_at(i, a);
            vector<int> bb = delete_at(j, b);
            ans = max(ans, get_score(n - 1, aa, bb));
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
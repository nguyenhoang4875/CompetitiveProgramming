#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int l, r;

int minOperations(vector<int>& a, vector<int>& b) {
    if(n * r < m * l || n * l > m * r) {
        return - 1;
    }
    int sumA = 0, sumB = 0;
    for (int e: a) sumA += e;
    for (int e: b) sumB += e;
    if(sumA > sumB) return minOperations(b, a);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> mi;
    for(int e: a) mi[r - e]++; // count increase sumA
    for(int e: b) mi[e - l]++; // count decrease sumB
    int i = r - 1;
    int cnt = 0;
    while(sumB > sumA) {
        while(mi[i] == 0) {
            i--;
        }
        sumA += i;
        mi[i]--;
        cnt++;
    }
    return cnt;    
}
void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] ;
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    cin >> l >> r;
    cout << minOperations(a, b);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
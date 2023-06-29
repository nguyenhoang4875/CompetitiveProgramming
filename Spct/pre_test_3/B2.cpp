#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[105];
int l, r;
int oo = 2e9;

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> l >> r;
    sort(a + 1, a + n + 1);
    vector<pair<int, int>> candidates;
    
    //handle left case 
    int val = l;
    int minVal = oo;
    for(int i = 1; i <= n; i++) {
        minVal = min(minVal, abs(a[i] - val));
    }
    candidates.push_back({val, minVal});

    //handle right case 
    val = r;
    minVal = oo;
    for(int i = 1; i <= n; i++) {
        minVal = min(minVal, abs(a[i] - val));
    }
    candidates.push_back({val, minVal});

    // for other cases
    for(int i = 1; i <= n; i++) {
        int dist = a[i+1] - a[i];
        val = a[i] + dist / 2;
        if(l <= val && val <= r) {
            candidates.push_back({val, dist/2});
        }
    }

    sort(candidates.begin(), candidates.end(), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    });
    cout << candidates[0].first << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
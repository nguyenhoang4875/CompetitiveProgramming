#include<bits/stdc++.h>

using namespace std;
/**
 * This source for C and D problem
 * https://codeforces.com/contest/1800/problem/C1
 * https://codeforces.com/contest/1800/problem/C2
*/

int tcs, n;
string s;

void solve() {
    vector<int> vi;
    cin >> n; 
    int x;
    for (int i = 1; i <= n ; i++) {
        cin >> x;
        vi.push_back(x);
    }
    long long ans = 0;

    priority_queue<int> pq;
    for (int i = 0; i < vi.size() ; i++) {
        if(vi[i] != 0) {
            pq.push(vi[i]);
        } else {
            if(!pq.empty()) {
                int val = pq.top();
                pq.pop();
                ans += val;
            }
        }
    }
    cout << ans << endl;

}
int main() {
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
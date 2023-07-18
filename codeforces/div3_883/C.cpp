#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m, h;

struct node{
    int id, val, pen;
};
vector<node> v;

void solve() {
    v.clear();
    cin >> n >> m >> h;
    for(int i = 1; i <= n; i++) {
        int a[m + 1];
        for(int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + m + 1);
        if(a[1] > h) {
            v.push_back({i, 0, 0});
            continue;
        }
        int val = 1;

        int pen = a[1];
        int sum = a[1];
        int temp;
        for(int i = 2; i <= m; i++) {
            sum += a[i];
            temp = pen + sum;
            // cout << "pen " << pen << endl;
            if(sum <= h) {
                val++;
                pen = temp;

            } else {
                break;
            }
        }
        v.push_back({i, val, pen});
            
    }
    
    // cout << "size = " << v.size() << endl;

    sort(v.begin(), v.end(), [&](node n1, node n2) {
        if(n1.val == n2.val) {
            if(n1.pen == n2.pen) return n1.id < n2.id;
            return n1.pen < n2.pen;
        }
        return n1.val > n2.val;
    });
    // for(int i = 0; i < n; i++) {
    //     cout << v[i].id << " " << v[i].val << " " << v[i].pen << endl;
    // }

    for(int i = 0; i < n; i++) {
        if(v[i].id == 1) {
            cout << i + 1 << "\n";
            return;
        }
    }


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    
    return 0;
}
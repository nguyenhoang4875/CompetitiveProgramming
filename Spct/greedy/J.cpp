#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1304/problem/C
 * Solution:
 *  1. Merge all customer who come the same time
 *  2. Find the min and max time of Air conditioner can reach
 *      then with time of each customer
 *  3. Check satisfy of each customer
 * TC: O(n) // n: number of customers
 * MC: O(n)
 * 
*/

#define pb push_back

//*** START CODING ***//

int tcs, n, m;

struct node {
    int t, l, r;
};

vector<node> v;
bool found = true;

// merge time
pair<int, int> unionTime(int ml, int mr, int l, int r) {
    if(ml > r || l > mr) {
        found = false;
        return {-1, -1};
    } else {
        ml = max(ml, l);
        mr = min(mr, r);
        return {ml, mr};
    }
}

// merge mode node
void unionNode(node& nd, int l, int r){
    int l1 = nd.l;
    int r1 = nd.r;
    if(l > r1 || l1 > r) found = false;
    else {
        nd.l = max(l1, l);
        nd.r = min(r1, r);
    }
}

void solve() {
    cin >> n >> m;
    v.clear();
    int t, l, r;
    found = true;
    for(int i = 0; i < n; i++) {
        cin >> t >> l >> r;
        if(i != 0 && t == v.back().t) {
            // if same time, merge them
            unionNode(v.back(), l, r);
        } else {
            v.pb({t, l, r});
        }
    }
    if(!found) {
        cout << "NO\n";
        return;
    }
    n = v.size();
    int ml, mr;
    ml = mr = m;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            ml = m - v[i].t;
            mr = m + v[i].t;
        } else {
            int dt = v[i].t - v[i-1].t;
            ml = ml - dt;
            mr = mr + dt;
        }
        pair<int, int> p = unionTime(ml, mr, v[i].l, v[i].r);
        ml = p.first;
        mr = p.second;

        if(!found) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}
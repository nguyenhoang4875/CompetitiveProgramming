#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/16201
 * Solution: Construction
 * - Using map to save undamaged cells
 *  (max: 1000 cell, but r <= 1e9, y <= 1e9)
 * - Count tiles and count way
 * 
 * TC: O(k * log(k))
 * MC: O(k * k)
*/


//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int mod = 1e9 + 7;
int r, c, k;

struct node {
    int r, c;
};


int getWay(int x) {
    if(x & 1) return (x + 1) / 2;
    else return 1;
}

int getTile(int x) {
    return x / 2;
}

// power recursion mode p
int powerRecMod(int a, int n, int p) {
    if (n == 0) return 1;  // base case
    int ans = powerRecMod(a, n / 2, p);
    ans = (ans * ans) % p;
    if (n & 1) ans = (ans * a) % p;
    return ans;
}

void solve() {
    cin >> r >> c >> k;
    // cout << r << c << k;
    // mp.resize(k + 1);
    unordered_map<int, vi> mp;
    int x, y;
    while (k--) {
        cin >> x >> y;
        mp[x].pb(y);
    }

    int sumBlock = 0;
    int sumWay = 1;
    int rm = r;
    for(auto e: mp) {
        if(!e.second.empty())rm--;
    }
    sumBlock += rm * getTile(c);
    sumWay *= powerRecMod(getWay(c), rm, mod);

    for(auto e: mp) {
        sort(e.second.begin(), e.second.end());
        int start = 0;
        int dist = 0;
        for(auto e2: e.second) {
            dist = e2 - start - 1;
            if(dist >= 2) {
                sumBlock += getTile(dist);
                sumWay = (sumWay % mod) * (getWay(dist) % mod) % mod;
            }
            start = e2;
        }

        // for last element in e.second
        dist = c - e.second.back();

        if(dist >= 2) {
            sumBlock += getTile(dist);
            sumWay = (sumWay % mod) * (getWay(dist) % mod) % mod;
        }

    }
    cout << sumBlock << " " << sumWay << '\n';
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
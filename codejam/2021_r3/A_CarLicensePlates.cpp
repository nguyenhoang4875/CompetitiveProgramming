#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21980
 * Solution:
 *  - Convert lowercase to uppercase
 *  - count the number of lowercase
 *  - Using unordered_map of custom object
 *  - Cal C(2, n)
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, k;
string a[10005];

struct node {
    string key;
    int num;

    // override operator == to compare in unordered_map
    bool operator == (const node &n) const {
        return key == n.key && num == n.num;
    }
};

// hash function to using for hashtable
struct hash_node {
    size_t operator() (const node& n) const {
        return (hash<int>() (n.num) ^ hash<string>()(n.key));
    }
};

void solve() {
    cin >> n >> k;
    string s;
    int cnt = 0;
    unordered_map<node, int, hash_node> mp;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        cnt = 0;
        for(int j = 0; j < s.size(); j++) {
            if('a' <= s[j] && s[j] <= 'z') {
                s[j] -= 32;
                cnt++;
            }
        }
        sort(s.begin(), s.end());
        mp[{s, cnt}]++;
    }

    int ans = 0;
    for(auto e : mp ) {
        // cout << e.first.key << " " << e.first.num << endl;
        int t = e.second;
        if(t >= 2) {
            ans += t * (t - 1) / 2; 
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
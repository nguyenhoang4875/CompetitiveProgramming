#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
string s;


void solve() {
    cin >> s;
    n = s.size();
    int cnt = 4;
    for(int i = 1; i < n; i++) {
        int c1 = s[i - 1]  - '0';
        int c2 = s[i] - '0';
        if(c1 == 0) c1 += 10;
        if(c2 == 0) c2 += 10;
        int t = abs(c1 - c2);
        // cout << "t = " << t << endl;
        cnt += abs(c1 - c2);
    }
    int f = s[0] - '0';
    if(f == 0) f += 9;
    else f = f - 1; 
    cnt += f;
    cout << cnt << '\n';

    

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
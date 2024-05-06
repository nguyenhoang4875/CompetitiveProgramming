#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, r;

void solve() {
    cin >> n >> m >> r;

    vi milks(n);
    for(auto &x: milks) cin >> x;
    sort(all(milks), greater<int>());

    vii shops(m);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        shops[i] = {b, a};
    }
    sort(all(shops), greater<pii>());

    vi rents(r);
    for(auto &x: rents) cin >> x;
    sort(all(rents), greater<int>());

    int cowAt = 0, shopAt = 0, rentAt = 0;
    int maxMoney = 0;

    while (cowAt < n) {
        int soldMoney = 0;
        int mq = milks[cowAt];
        int last = 0;
        int curShop = shopAt;

        while(curShop < m) {
            int sold = min(mq, shops[curShop].S);
            soldMoney += sold * shops[curShop].F;
            mq -= sold;
            
            if(mq == 0) {
                last = sold;
                break;
            }
            curShop++;
        }
        // take sold if better
        if(rentAt >= r or soldMoney > rents[rentAt]) {
            maxMoney += soldMoney;
            shopAt = curShop;

            if(shopAt < m) {
                shops[shopAt].S -= last;
            }
            cowAt++;
        } else {
            // rent
            maxMoney += rents[rentAt];
            rentAt++;
            n--;
        }
    }
    cout << maxMoney << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}
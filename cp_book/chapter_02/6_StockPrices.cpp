#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;

    priority_queue<pii> bid;                     // {price, num}
    priority_queue<pii, vii, greater<pii>> ask;  // {price, num}
    int stock_price = -1;
    while (n--) {
        string type, tmp;
        int num, price;
        cin >> type >> num >> tmp >> tmp >> price;

        if (type == "buy") {
            while (ask.size() and num > 0 and price >= ask.top().F) {
                auto cur = ask.top();
                ask.pop();
                stock_price = cur.F;
                int num_trade = min(num, cur.S);
                num -= num_trade;
                cur.S -= num_trade;
                if (cur.S) {
                    ask.push({cur.F, cur.S});
                }
            }
            if (num > 0) bid.push({price, num});
        } else {
            while (bid.size() and num > 0 and price <= bid.top().F) {
                auto cur = bid.top();
                bid.pop();
                stock_price = price;
                int num_trade = min(num, cur.S);
                num -= num_trade;
                cur.S -= num_trade;
                if (cur.S) {
                    bid.push({cur.F, cur.S});
                }
            }
            if (num > 0) ask.push({price, num});
        }
        if (ask.empty()) cout << "- ";
        else cout << ask.top().F << " ";

        if (bid.empty()) cout << "- ";
        else cout << bid.top().F << " ";

        if (stock_price == -1) cout << "-";
        else cout << stock_price;
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
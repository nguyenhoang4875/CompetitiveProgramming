#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, m;

void solve() {
    cin >> n >> m;
    priority_queue<int> qa, qb;
    For(i, 1, n) {
        int x;
        cin >> x;
        qa.push(x);
    }
    For(i, 1, m) {
        int x;
        cin >> x;
        qb.push(x);
    }
    int cnt = 0;
    while (qa.size() and qb.size()) {
        if (qa.top() > qb.top()) {
            cout << "NO" << el;
            return;
        }
        if (qa.top() == qb.top()) {
            qa.pop();
            qb.pop();
        } else {
            int x = qb.top();
            qb.pop();
            qb.push(x / 2);
            qb.push(x - x / 2);
            cnt++;
            if (cnt > n - m) {
                cout << "NO" << el;
                return;
            }
        }
    }
    if (qa.empty() and qb.empty()) {
        cout << "YES" << el;
    } else
        cout << "NO" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
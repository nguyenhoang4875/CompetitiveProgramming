#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
int n, d, f;

void solve() {
    cin >> n;
    vii a(n);
    for (auto& x : a) cin >> x.F >> x.S;
    sort(all(a), greater<pii>());

    a.push_back({0, 0});
    cin >> d >> f;
    int cnt = 0;
    priority_queue<int> q;

    for (auto& [pos, fuel] : a) {
        int travelDist = d - pos;

        while (f < travelDist) {
            if (q.empty()) {
                cout << -1 << el;
                return;
            }
            cnt++;
            f += q.top();
            q.pop();
        }

        f -= travelDist;
        d = pos;
        q.push(fuel);
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
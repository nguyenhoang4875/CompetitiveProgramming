#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

struct event {
    int time, id, status;
};

void solve() {
    cin >> n;
    vector<event> events;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        events.push_back({l, i, 1});
        events.push_back({r, i, -1});
    }

    sort(all(events), [&](event e1, event e2) { return e1.time < e2.time; });

    vector<int> aloneTime(n);
    set<int> active;

    int preTime = 0, totalTime = 0;
    for (auto e : events) {
        int curTime = e.time;
        if (active.size() > 0) {
            totalTime += curTime - preTime;
        }

        // previous start time and then meet end time
        if (active.size() == 1) {
            int id = *active.begin();
            aloneTime[id] = curTime - preTime;
        }

        if (e.status == 1) {
            // start time
            active.insert(e.id);
        } else {
            active.erase(e.id);
        }

        preTime = curTime;
    }

    int aloneMinTime = *min_element(all(aloneTime));
    int ans = totalTime - aloneMinTime;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    solve();
    return 0;
}
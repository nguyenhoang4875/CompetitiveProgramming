#include <bits/stdc++.h>
using namespace std;
#define int long long
#define size(a) (int)(a.size())
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)

string color = "RGB";
int n[5];
string s[5];
int cnt[5][300];

struct node {
    int r, g, b;
    void add(int ch, int val) {
        if (ch == 'R') r += val;
        if (ch == 'G') g += val;
        if (ch == 'B') b += val;
    }
};

int cal(int id, char chhh) {
    vector<int> n;
    for (int i = 1; i <= 3; i++) {
        if (id != i) n.push_back(i);
    }
    vector<char> c;
    for (auto ch : color) {
        if (ch != chhh) c.push_back(ch);
    }
    int res = 0;
    res += cnt[n[0]][c[0]] * cnt[n[1]][c[1]];
    res += cnt[n[0]][c[1]] * cnt[n[1]][c[0]];
    //	cout << id << " " << chhh << " " << res << "\n";
    return res;
}

int calCurVal() {
    int res = 0;
    vector<int> hv = {1, 2, 3};
    do {
        int n1 = hv[0];
        int n2 = hv[1];
        int n3 = hv[2];
        res += cnt[n1]['R'] * cnt[n2]['G'] * cnt[n3]['B'];
    } while (next_permutation(hv.begin(), hv.end()));
    //	cout << res << "\n";
    return res;
}

void solve() {
    cin >> n[1] >> n[2] >> n[3];
    cin >> s[1] >> s[2] >> s[3];
    for (int i = 1; i <= 3; i++) {
        for (auto ch : color) {
            cnt[i][ch] = 0;
            for (int j = 0; j <= size(s[i]) - 2; j++) {
                if (s[i][j] == ch && s[i][j] == s[i][j + 1]) cnt[i][ch]++;
            }
        }
    }

    int curVal = calCurVal();
    vector<node> listNode[4];
    for (int i = 1; i <= 3; i++) {
        unordered_map<int, bool> check;
        for (int j = 0; j < size(s[i]); j++) {
            for (auto ch : color) {
                if (ch == s[i][j]) continue;
                node mynode = {0, 0, 0};
                // +
                if (j - 1 >= 0 && ch == s[i][j - 1]) mynode.add(ch, 1);
                if (j + 1 < size(s[i]) && ch == s[i][j + 1]) mynode.add(ch, 1);
                // -
                if (j - 1 >= 0 && s[i][j] == s[i][j - 1]) mynode.add(s[i][j], -1);
                if (j + 1 < size(s[i]) && s[i][j] == s[i][j + 1]) mynode.add(s[i][j], -1);
                int hash = (mynode.r + 5) * 10 + (mynode.g + 5) * 100 + (mynode.b + 5) * 1000;
                if (!check[hash]) {
                    listNode[i].push_back(mynode);
                    check[hash] = true;
                }
            }
        }
    }
    for (int i = 1; i <= 3; i++) {
        listNode[i].push_back({0, 0, 0});
    }
    int ans = curVal;
    for (auto p1 : listNode[1]) {
        cnt[1]['R'] += p1.r;
        cnt[1]['G'] += p1.g;
        cnt[1]['B'] += p1.b;
        for (auto p2 : listNode[2]) {
            cnt[2]['R'] += p2.r;
            cnt[2]['G'] += p2.g;
            cnt[2]['B'] += p2.b;
            for (auto p3 : listNode[3]) {
                cnt[3]['R'] += p3.r;
                cnt[3]['G'] += p3.g;
                cnt[3]['B'] += p3.b;
                // go go go
                int newVal = calCurVal();
                ans = max(ans, newVal);
                cnt[3]['R'] -= p3.r;
                cnt[3]['G'] -= p3.g;
                cnt[3]['B'] -= p3.b;
            }
            cnt[2]['R'] -= p2.r;
            cnt[2]['G'] -= p2.g;
            cnt[2]['B'] -= p2.b;
        }
        cnt[1]['R'] -= p1.r;
        cnt[1]['G'] -= p1.g;
        cnt[1]['B'] -= p1.b;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
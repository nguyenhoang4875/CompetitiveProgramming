#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
int n, q;
string s[105];

void solve() {
    cin >> n >> q;
    string xxx;
    getline(cin, xxx);
    for (int i = 0; i < n; i++) {
        getline(cin, s[i]);
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
    }
    while (q--) {
        string ts;
        getline(cin, ts);
        string qr = "";
        for (auto e : ts) {
            if (e != ' ') {
                qr += tolower(e);
            }
        }
        int cnt = 0;
        int qn = qr.size();
        for (int t = 0; t < n; t++) {
            int stz = s[t].size();
            if (stz < qn) continue;
            for (int k = 0; k < stz; k++) {
                if (qr[0] != s[t][k]) continue;
                if (k == 0 || (k > 0 && s[t][k - 1] == ' ')) {
                    int tk = k;
                    string at = "";
                    int ct = 0;
                    while (ct < qn && tk < stz) {
                        if (s[t][tk] == ' ') {
                            tk++;
                            continue;
                        }
                        at += s[t][tk];
                        tk++;
                        ct++;
                    }
                    if (at == qr) {
                        cnt++;
                        k = tk;
                        break;
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
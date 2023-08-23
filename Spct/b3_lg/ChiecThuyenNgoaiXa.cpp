#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

//*** START CODING ***//
int n, xa, ya, xb, yb;
vector<pii> v;
int gb[15];
vi va;
vi vb;
int oo = 1e9;
int ans = oo;

int calDistance(int x1, int y1, int x2, int y2, int t) {
    return (abs(x1 - x2) + abs(y1 - y2)) * t;
}

void calGenBi() {
    va.clear();
    vb.clear();
    for (int i = 0; i < n; i++) {
        if (gb[i]) va.pb(i);
        else vb.pb(i);
    }
    int na = va.size();
    int nb = vb.size();
    int sumA = oo;
    int t = 0;
    if (na == 0)
        sumA = 0;
    else {
        do {
            int sa = 0;
            t = 0;
            sa += calDistance(xa, ya, v[va[0]].first, v[va[0]].second, t);
            for (int i = 0; i < na - 1; i++) {
                t++;
                sa += calDistance(v[va[i]].first, v[va[i]].second,
                                  v[va[i + 1]].first, v[va[i + 1]].second, t);
            }
            t++;
            sa +=
                calDistance(xa, ya, v[va[na - 1]].first, v[va[na - 1]].second, t);
            sumA = min(sumA, sa);
        } while (next_permutation(va.begin(), va.end()));
    }
   
    int sumB = oo;
    if (nb == 0)
        sumB = 0;
    else {
        do {
            int sb = 0;
            t = 0;
            sb += calDistance(xb, yb, v[vb[0]].first, v[vb[0]].second, t);
            for (int i = 0; i < nb - 1; i++) {
                t++;
                sb += calDistance(v[vb[i]].first, v[vb[i]].second,
                                  v[vb[i + 1]].first, v[vb[i + 1]].second, t);
            }
            t++;
            sb += calDistance(xb, yb, v[vb[nb - 1]].first, v[vb[nb - 1]].second, t);
            sumB = min(sumB, sb);
        } while (next_permutation(vb.begin(), vb.end()));
    }
    ans = min(ans, sumA + sumB);
}
void genBi(int i) {
    if (i == n) {
        calGenBi();
        return;
    }
    for (int val = 0; val <= 1; val++) {
        gb[i] = val;
        genBi(i + 1);
    }
}

void solve() {
    cin >> n;
    v.resize(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        v[i] = {x, y};
    }
    cin >> xa >> ya >> xb >> yb;
    genBi(0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
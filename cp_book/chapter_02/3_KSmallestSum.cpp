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
const int ms = 750 + 5;
int n;

void merge(int a[], int b[], int c[], int k) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;  // Every pair contains value and position.

    for (int i = 0; i < k; ++i) pq.push(pii(a[i] + b[0], 0));

    int idx = 0;

    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop();
        c[idx++] = t.F;

        if (t.S + 1 < k) pq.push(pii(t.F - b[t.S] + b[t.S + 1], t.S + 1));

        if (idx == k) break;
    }
}

void solve() {
    int k, arr1[ms], arr2[ms];

    while (cin >> k) {
        for (int i = 0; i < k; ++i) cin >> arr1[i];
        sort(arr1, arr1 + k);

        for (int i = 1; i < k; ++i) {
            for (int j = 0; j < k; ++j) cin >> arr2[j];
            sort(arr2, arr2 + k);
            merge(arr1, arr2, arr1, k);
        }

        for (int i = 0; i < k; ++i) cout << arr1[i] << " \n"[i == k - 1];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

void merge(vi& a, int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    vi temp;
    while (i <= mid and j <= e) {
        if (a[i] <= a[j])
            temp.pb(a[i++]);
        else
            temp.pb(a[j++]);
    }
    while (i <= mid) temp.pb(a[i++]);
    while (j <= e) temp.pb(a[j++]);
    int k = 0;
    for (int i = s; i <= e; i++) {
        a[i] = temp[k++];
    }
}

void mergeSort(vi& a, int s, int e) {
    if (s >= e) return;
    int mid = (s + e) / 2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    merge(a, s, e);
}

void solve() {
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;

    for (auto x : a) cout << x << " ";
    cout << el;
    mergeSort(a, 0, n - 1);

    for (auto x : a) cout << x << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
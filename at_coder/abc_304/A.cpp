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
const int ms = 2e5 + 5;
int n;

struct node {
    string name;
    int age;
};

void solve() {
    cin >> n;
    vector<node> v(n);
    string name;
    int age;
    int idx_min_age = 0;
    int min_age = oo;
    For(i, 0, n - 1) {
        cin >> name >> age;
        v[i] = {name, age};
        if(age < min_age) {
            min_age = age;
            idx_min_age = i;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << v[(i + idx_min_age) % n].name << el;
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
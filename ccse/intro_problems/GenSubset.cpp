#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;


vector<int> subset;

void search(int k) {
    if(k == n + 1) {
        // process subset
        for(int e: subset) cout << e << ' ';
        if(subset.size() == 0) cout << "empty";
        cout << '\n';
    } else {
        subset.push_back(k); // add k in the subset
        search(k + 1);
        subset.pop_back(); // remove k in the subset
        search(k + 1);
    }
}

void solve() {
    cin >> n;
    search(1);


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
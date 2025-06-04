#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        // Sort p
        sort(p.begin(), p.end(), greater<int>());
        for (auto e : p) cout << e << " ";
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!getline(cin, a)) return 0;
    if (!getline(cin, b)) return 0;

    int n = a.size();
    int m = b.size();
    const int INF = n + 5;

    // 1) Build prefix array: pref[i] = smallest index in a where b[0..i-1] matches as subsequence
    vector<int> pref(m + 1, INF);
    pref[0] = -1;
    int pos = 0;
    for (int i = 1; i <= m; i++) {
        while (pos < n && a[pos] != b[i-1]) {
            pos++;
        }
        pref[i] = (pos < n ? pos : INF);
        pos++;
    }

    // 2) Build suffix array: suff[j] = largest index in a where b[j..m-1] matches as subsequence
    vector<int> suff(m + 1, -INF);
    suff[m] = n;
    pos = n - 1;
    for (int j = m - 1; j >= 0; j--) {
        while (pos >= 0 && a[pos] != b[j]) {
            pos--;
        }
        suff[j] = (pos >= 0 ? pos : -INF);
        pos--;
    }

    // 3) Two-pointer scan to find minimal-length removable block
    int best_len = m + 1, best_i = 0;
    int j = 0;
    for (int i = 0; i <= m; i++) {
        // Move j forward until the suffix match starts after the prefix match
        while (j <= m && !(suff[j] > pref[i])) {
            j++;
        }
        if (j > m) break;
        if (j - i < best_len) {
            best_len = j - i;
            best_i = i;
        }
    }

    // 4) Output result
    if (best_len >= m) {
        // Must remove all of b
        cout << "-\n";
    } else {
        // Splice out b[best_i .. best_i+best_len-1]
        int remove_start = best_i;
        int remove_end = best_i + best_len;  // one past the last removed
        string result = b.substr(0, remove_start) + b.substr(remove_end);
        cout << result << "\n";
    }

    return 0;
}

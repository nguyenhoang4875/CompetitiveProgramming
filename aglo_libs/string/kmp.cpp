#include <bits/stdc++.h>
using namespace std;

vector<int> kmpPrepare(const string& P) {
    int m = P.size();
    vector<int> b(m + 1);
    int j = -1;
    b[0] = j;

    for (int i = 0; i < m; ++i) {
        while ((j >= 0) && (P[i] != P[j])) j = b[j];
        ++j;
        b[i + 1] = j;
    }
    return b;
}

int kmpSearch(const string& T, const string& P, const vector<int>& b) {
    int freq = 0;
    int n = T.size();
    int m = P.size();

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while ((j >= 0) && (T[i] != P[j])) j = b[j];
        ++j;
        if (j == m) {
            ++freq;
            // cout << "P is found at index " << i - j + 1 << " in T" << endl;
            j = b[j];
        }
    }
    return freq;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string T, P;
    cin >> T >> P;

    vector<int> b = kmpPrepare(P);
    kmpSearch(T, P, b);

    return 0;
}

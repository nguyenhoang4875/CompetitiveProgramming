#include <bits/stdc++.h>

#include <chrono>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    cout << "n = " << n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("../../input.txt", "r", stdin);
    // freopen("../../output.txt", "w", stdout);

    auto start = chrono::system_clock::now();

    solve();

    auto end = chrono::system_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << "ms" << std::endl;
    return 0;
}

/*
 * stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * i and j are misplaced
 * variable misuse
 * do something instead of nothing and stay organized
 * vector cause MLE or TLE
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
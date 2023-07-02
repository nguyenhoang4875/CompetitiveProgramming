#include <bits/stdc++.h>
#define int long long

using namespace std;

bool isSorted(int a[], int n) {
    // base case
    if(n == 1 || n == 0) return true;

    // rec case
    if(a[0] < a[1] and isSorted(a + 1, n - 1)) return true;
    return false;
}

bool isSortedTwo(int a[], int i, int n) {
    if(i == n - 1) return true;
    if(a[i] < a[i+1] and isSortedTwo(a, i + 1, n)) return true;
    return false;
}

void solve() {
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);

    cout << isSorted(a, n) << endl;
    cout << isSortedTwo(a, 0, n) << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
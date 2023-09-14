#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/*
Problem: https://codejam.lge.com/problem/16238
Solution:
1. the maximum number of lambs the eagle can eat.
There are N cells and the eagle eat A cells for A days.
At this case,  there are equal or less than N lambs in the other cells (N-A
cells). That's why there are no lambs after A days. (There can be several cells
having A lambs.)

If you eat lambs in less than A cells., you can't eat more than lambs in A
cells. And also if you eat lambs in more than A cells, you can't eat more eating
lambs in A cells.

> Problem Example : 1   10   4  10  1  =>  3 cells that there are more than 3
lambs  => A : 3

2. The sequence of selecting cell!

If you select the cell having more than A lambs, it doesn't matter the sequence
selecting cell. If the number of lambs in cell  assume f(n), the sum is like
below. (1 <= n <= A)

SUM =  {f(1) - 0} + {f(2) - 1} + ... + {f(n-1) - (n-2)} + {f(n) - (n-1)}  =
{f(1) ~ f(n)} - { 1 + 2 + 3 + ... (n-1) }

Therefore, the best solution is that the eager start to eat lambs in the cell
having the biggest number of lambs.
*/

void solve() {
    int n;
    cin >> n;
    int a[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<>());
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i) {
            sum += a[i] - i + 1;
        } else
            break;
    }
    cout << sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
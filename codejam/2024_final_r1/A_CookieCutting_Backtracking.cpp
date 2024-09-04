#include <bits/stdc++.h>
#define int long long
using namespace std;

int getSum(const vector<vector<int>>& a, int row, int col, int size) {
    int sum = 0;
    for (int i = row; i < row + size; ++i) {
        for (int j = col; j < col + size; ++j) {
            sum += a[i][j];
        }
    }
    return sum;
}

int cal(vector<vector<int>>& a, int row, int col, int size) {
    if (size == 1) {
        return a[row][col];
    }

    int half = size / 2;
    int sums[4];

    sums[0] = getSum(a, row, col, half);                // top-left
    sums[1] = getSum(a, row, col + half, half);         // top-right
    sums[2] = getSum(a, row + half, col, half);         // bottom-left
    sums[3] = getSum(a, row + half, col + half, half);  // bottom-right

    int chosenIndex = (sums[0] + sums[1] + sums[2] + sums[3]) % 4;

    int eatingSum = 0;
    eatingSum += sums[chosenIndex];
    if (size > 2) {
        if (chosenIndex != 0) eatingSum += cal(a, row, col, half);
        if (chosenIndex != 1) eatingSum += cal(a, row, col + half, half);
        if (chosenIndex != 2) eatingSum += cal(a, row + half, col, half);
        if (chosenIndex != 3) eatingSum += cal(a, row + half, col + half, half);
    }

    return eatingSum;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char tmp;
            cin >> tmp;
            a[i][j] = tmp - '0';
            sum += a[i][j];
        }
    }
    cout << sum - cal(a, 0, 0, n) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
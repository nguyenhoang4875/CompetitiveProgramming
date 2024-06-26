#include <bits/stdc++.h>
#define int long long

using namespace std;

random_device rd;
mt19937 gen(rd());
int random(int l, int r) {
    uniform_int_distribution<int> dis(l, r);
    return dis(gen);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 10;
    int minVal = 0, maxVal = 100;
    for (int i = 1; i <= n; i++) {
        cout << random(minVal, maxVal) << " ";
    }
    cout << endl;

    return 0;
}
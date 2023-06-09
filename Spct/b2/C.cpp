#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
void solve() {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    stack<int> s1, s2;
    s1.push(arr[0]);
    int cnt = 0;
    int i = 1;
    while (i < n) {
        if (!s1.empty() && arr[i] >= s1.top()) {
            // cout << i << " " << s1.top() << endl;
            s1.pop();
            cnt++;
        } else {
            s1.push(arr[i]);
            i++;
        }
    }
    s2.push(arr[n - 1]);
    int j = n - 2;
    cout << endl;
    while (j >= 0) {
        if (!s2.empty() && arr[j] >= s2.top()) {
            if(arr[j] != s2.top()) cnt++;
            // cout << j << " " << s2.top() << endl;;
            s2.pop();
        } else {
            s2.push(arr[j]);
            j--;
        }
    }
    cout << cnt << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
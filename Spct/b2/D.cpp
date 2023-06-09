#include <bits/stdc++.h>
#define int long long

using namespace std;

void nextGreaterElement(int a[], int n) {
    stack<int> st;
    vector<int> ans(n, -1);
    st.push(a[n-1]);
    for(int i = n-2; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i]) {
            st.pop();
        }
        if(!st.empty()) {
            ans[i] = st.top();
        }
        st.push(a[i]);
    }
    for(int e: ans) cout << e << " ";
    cout << "\n";

}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    nextGreaterElement(a, n);

    return 0;
}
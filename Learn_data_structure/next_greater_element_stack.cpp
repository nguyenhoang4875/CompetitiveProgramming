#include <bits/stdc++.h>
#define int long long

using namespace std;

void nextGreaterElement(int a[], int n) {
    stack<int> st;
    st.push(a[0]);
    for(int i = 1; i < n; i++) {
        while (!st.empty() && st.top() < a[i]) {
            cout << st.top() << " -> " << a[i] << "\n";
            st.pop();
        }
        st.push(a[i]);
    }
    while (!st.empty()) {
        cout << st.top() << " -> " << "-1\n";
        st.pop();
    }

}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 6;
    int a[] = {5, 1, 2, 3, 4, 6};

    nextGreaterElement(a, n);

    return 0;
}
#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

/*
    count number of pair (i, j) such that all element between (i, j) less than both a[i] and a[j]
    solution: using stack

*/
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    stack<int> st;
    for(int i = n; i >= 1; i--) {
        while(!st.empty() and a[i] > a[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            if(st.top() - i >= 2) cnt++;
        }
        st.push(i);
    }

    st = stack<int>();
    reverse(a + 1, a + n + 1);
    for(int i = n; i >= 1; i--) {
        while(!st.empty() and a[i] > a[st.top()]) {
            st.pop();
        }
        if(!st.empty()) {
            if(st.top() - i >= 2 and a[i] != a[st.top()]) cnt++;
        }
        st.push(i);
    }
    cnt += n - 1;
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
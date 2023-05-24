#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void increasingStack(int a[], int n) {
    cout << "increasingStack: " << endl;
    stack<int> st;

    st.push(a[0]);
    for (int i = 1; i < n; i++) {

        while (!st.empty() && st.top() > a[i]) {
            st.pop();
        }
        st.push(a[i]);
    }
    vector<int> num;
    while (!st.empty()) {
        num.push_back(st.top());
        st.pop();
    }
    reverse(num.begin(), num.end()); 
    for(int e: num) cout << e << " ";
    cout << endl;
}

void decreasingStack(int a[], int n) {
    cout << "decreasingStack" << endl;
    stack<int> st;
    st.push(a[0]);
    for(int i = 1; i < n; i++) {

        while(!st.empty() && st.top() < a[i]) {
            st.pop();
        }
        st.push(a[i]);
    }
    vector<int> num;
    while (!st.empty()) {
        num.push_back(st.top());
        st.pop();
    }
    reverse(num.begin(), num.end()); 
    for(int e: num) cout << e << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 6;
    int a[] = {1, 4, 5, 3, 12, 10};

    increasingStack(a, n);
    decreasingStack(a, n);
}
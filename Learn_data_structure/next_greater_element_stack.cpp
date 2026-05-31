#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> prevGreaterIdx(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> st;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        res[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return res;
}

vector<int> nextGreaterIdx(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> st;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] <= a[i]) st.pop_back();
        res[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return res;
}

vector<int> prevSmallerIdx(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> st;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        res[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return res;
}

vector<int> nextSmallerIdx(const vector<int>& a) {
    int n = (int)a.size();
    vector<int> st;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.back()] >= a[i]) st.pop_back();
        res[i] = st.empty() ? -1 : st.back();
        st.push_back(i);
    }
    return res;
}

pair<vector<int>, vector<int>> maxRangeLR(const vector<int>& a) {
    // For each i, compute [l[i], r[i]] such that a[i] is the STRICT maximum in that range.
    // l[i] = prevGreater(i) + 1, r[i] = nextGreater(i) - 1.
    int n = (int)a.size();
    vector<int> pg = prevGreaterIdx(a);
    vector<int> ng = nextGreaterIdx(a);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = (pg[i] != -1 ? pg[i] + 1 : 0);
        r[i] = (ng[i] != -1 ? ng[i] - 1 : n - 1);
    }
    return {l, r};
}

pair<vector<int>, vector<int>> minRangeLR(const vector<int>& a) {
    // For each i, compute [l[i], r[i]] such that a[i] is the STRICT minimum in that range.
    // l[i] = prevSmaller(i) + 1, r[i] = nextSmaller(i) - 1.
    int n = (int)a.size();
    vector<int> ps = prevSmallerIdx(a);
    vector<int> ns = nextSmallerIdx(a);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = (ps[i] != -1 ? ps[i] + 1 : 0);
        r[i] = (ns[i] != -1 ? ns[i] - 1 : n - 1);
    }
    return {l, r};
}

void printVec(const string& name, const vector<int>& v) {
    cout << name << ": ";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << (i + 1 == (int)v.size() ? "\n" : " ");
    }
}

void printNextValue(const string& name, const vector<int>& a, const vector<int>& idx) {
    cout << name << ": ";
    int n = (int)a.size();
    for (int i = 0; i < n; i++) {
        if (idx[i] == -1) cout << -1;
        else cout << a[idx[i]];
        cout << (i + 1 == n ? "\n" : " ");
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {5, 1, 2, 3, 4, 6};

    auto pg = prevGreaterIdx(a);
    auto ng = nextGreaterIdx(a);
    auto ps = prevSmallerIdx(a);
    auto ns = nextSmallerIdx(a);

    printVec("prevGreaterIdx", pg);
    printVec("nextGreaterIdx", ng);
    printVec("prevSmallerIdx", ps);
    printVec("nextSmallerIdx", ns);

    printNextValue("nextGreaterVal", a, ng);
    printNextValue("nextSmallerVal", a, ns);

    auto [lMax, rMax] = maxRangeLR(a);
    auto [lMin, rMin] = minRangeLR(a);
    printVec("lMax", lMax);
    printVec("rMax", rMax);
    printVec("lMin", lMin);
    printVec("rMin", rMin);

    return 0;
}
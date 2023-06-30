#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;

int popcount(int x) {
    int cnt = 0;
    for(int i = 0; i < 32; i++) {
        if((x >>  i) & 1) cnt++;
    }
    return cnt;
}

bool getBit(int x, int pos) {
    return x >> pos & 1;
}

void genSubsets(int n) {
    for(int b = 0; b < (1 << n); b++) {
        cout << b << endl;
        for(int i = n - 1; i >= 0; i--) {
            cout << getBit(b, i);
        }
        cout << endl;
    }
}

void genSubsetKElements(int n, int k) {
    for(int b = 0; b < (1 << n); b++) {
        if(__builtin_popcount(b) == k) {
            cout << b << endl;
            for(int i = n - 1; i >= 0; i--) {
                cout << getBit(b, i);
            }
            cout << endl;
        }
    }
}

void solve() {
    cin >> n;
    // genSubsets(n);
    // genSubsetKElements(n, n - 2);
    // cout << popcount(15) << endl;

    int x = n;
    int b = 0;
    do {
        // process subset b
        cout << b << endl;
        for(int i = n - 1; i >= 0; i--) {
            cout << getBit(b, i);
        }
        cout << endl;
    } while (b = (b-x) & x);
    

}

void bitSet(int n) {
    bitset<4> bs;
    bs.set();
    // bs[3] = 1;
    cout << bs.to_ulong();
    
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // solve();
    bitSet(4);
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1800/problem/B
*/

int tcs, n, k;
map<char, int> mc;
string s;

void solve() {
    cin >> n >> k;
    cin >> s; 
    int len = s.length();
    mc.clear();
    for (char c: s) {
        mc[c]++;
    }
    long diff = 0;
    long sum = 0;
    for (char c = 'A'; c <= 'Z' ; c++) {
        if(mc[c] == 0 &&  mc[(char) (c + 32)] == 0) continue;
        if(mc[c] > 0 &&  mc[(char) (c + 32)] > 0) {
            diff += abs(mc[c] - mc[(char) (c + 32)]) / 2;
            sum += min(mc[c], mc[(char) (c + 32)]);
        } else if(mc[c] > 0 && mc[(char) c + 32] == 0) {

            diff += mc[c] / 2;
        } else if (mc[c] == 0 && mc[(char) c + 32] > 0) {

            diff += mc[c + 32] / 2;

        }
    }
    int added = min(1L * k, diff);
    // cout << "before sum = " << sum << endl;
    sum += added;
    cout << sum << endl;
   
}
int main() {
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}
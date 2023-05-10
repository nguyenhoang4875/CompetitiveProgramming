#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1703/problem/C
*/
int tcs, n;
vector<int> pass;

void solve() {
    pass.clear();
    cin >> n;
    for (int i = 0; i < n ; i++) {
        int x;
        cin >> x;
        pass.push_back(x);
    }
    int len;
    string cmd;
    int index = 0;
    while (n--) {
        cin >> len;
        cin >> cmd;
        int diff = 0;
        for (int i = 0; i < len; i++) {
            if(cmd[i] == 'D') diff++;
            else diff--;
        }
        diff += 10;
        diff %= 10;

        pass[index] = (pass[index] + diff) % 10;
        index++;
    }

    for (int e: pass) {
        cout << e << " ";
    }
    cout << endl;

}


int main() {
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }

    return 0;
}
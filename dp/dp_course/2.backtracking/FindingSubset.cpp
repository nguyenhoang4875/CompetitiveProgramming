#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Given a string, find all subsets of given string
 * Input: abc
 * Output: "", a, b, c, ab, ac, bc, abc
*/

void findSubsets(char input[], char output[], int i, int j) {

    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        if(output[0] == '\0') {
            cout << "NULL";
        }
        cout << output << endl;
        return;
    }

    // rec case
    // include the i-th letter
    output[j] = input[i];
    findSubsets(input, output, i + 1, j+1);
    
    // exclude the i-th letter
    findSubsets(input, output, i + 1, j);
}

void solve() {
    char input[100];
    char output[100];

    cin >> input;
    findSubsets(input, output, 0, 0);

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
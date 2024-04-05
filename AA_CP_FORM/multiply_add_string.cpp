#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Addition and Multiply two string number (number can very large)
 *
 * n: length of num1(n = log10(num1))
 * m: length of num2(m = log10(num2))
 *
 * TC: O(n * m)
 * MC: O(n + m)
 */

// add two string numbers without sign
string addString(string num1, string num2) {
    int l1 = num1.length() - 1;
    int l2 = num2.length() - 1;
    int x = 0;
    int carry = 0;
    string answer = "";

    while (l1 >= 0 || l2 >= 0 || carry > 0) {
        int digit1 = (l1 >= 0) ? num1[l1] - '0' : 0;
        int digit2 = (l2 >= 0) ? num2[l2] - '0' : 0;
        x = digit1 + digit2 + carry;
        carry = x / 10;
        x = x % 10;

        answer = to_string(x) + answer;
        if (l1 >= 0) l1--;
        if (l2 >= 0) l2--;
    }

    return answer;
}

string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";

    vector<int> res(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;  // add carry
            res[i + j + 1] %= 10;               // take the modulo of 10
        }
    }

    int i = 0;
    string ans = "";
    while (res[i] == 0) i++;  // remove leading zero
    while (i < res.size()) ans += to_string(res[i++]);

    return ans;
}

string multiplyWithSign(string num1, string num2) {
    int signNum1 = 1;
    int signNum2 = 1;
    if (num1[0] == '-') {
        num1 = num1.substr(1);
        signNum1 = -1;
    }
    if (num2[0] == '-') {
        num2 = num2.substr(1);
        signNum2 = -1;
    }
    string sign = "";
    if (signNum1 * signNum2 < 0) sign = "-";

    if (num1 == "0" || num2 == "0") return "0";

    vector<int> res(num1.size() + num2.size(), 0);

    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;  // add carry
            res[i + j + 1] %= 10;               // take the modulo of 10
        }
    }

    int i = 0;
    string ans = "";
    while (res[i] == 0) i++;  // remove leading zero
    while (i < res.size()) ans += to_string(res[i++]);

    ans.insert(0, sign);  // add sign for answer
    return ans;
}

void solve() {
    string num1, num2;
    cin >> num1 >> num2;
    cout << multiplyWithSign(num1, num2) << endl;
    cout << addString(num1, num2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
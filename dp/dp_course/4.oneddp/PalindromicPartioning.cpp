#include <bits/stdc++.h>
#define int long long

using namespace std;

class Solution {
public: 

    map<int, vector<vector<string>>> mp;
    bool isPalindrome(int i, int j, string s) {
        while(i <= j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    vector<vector<string>> dp(int i, string s) {
        if(i == s.size()) return vector<vector<string>>();

        if(mp.count(i)) return mp[i];
        vector<vector<string>> ans;
        
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                vector<vector<string>> res = dp(j + 1, s);
                string substr = s.substr(i, j - i + 1);

                for(auto &x: res) {
                    x.insert(x.begin(), substr);
                }

                if(res.empty()) {
                    res.push_back({substr});
                }

                for(auto x: res) {
                    ans.push_back(x);
                }
            }
        }
        return mp[i] = ans;
    }

    vector<vector<string>> partition(string s) {
        return dp(0, s);
    }
};


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution h;
    string s;
    cin >> s;
    vector<vector<string>> res = h.partition(s);
    for(auto x: res) {
        for(auto e: x) {
            cout << e << " ";
        }
        cout << '\n';
    }

    return 0;
}
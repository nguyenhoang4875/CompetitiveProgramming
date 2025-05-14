#include <bits/stdc++.h>
using namespace std;

// mod index 1
int modIdx1(int i, int n) { return ((i - 1) % n + n) % n + 1; }

vector<string> split(string line) {
    // getline(cin, line); // if get from sdt in
    stringstream ss(line);
    vector<string> ans;
    string str;
    while (ss >> str) { ans.push_back(str); }
    return ans;
}

vector<string> split(const string& line, const string& deli) {
    vector<string> ans;
    size_t start = 0, pos;

    while ((pos = line.find(deli, start)) != string::npos) {
        ans.emplace_back(line.substr(start, pos - start));
        start = pos + deli.length();
    }

    ans.emplace_back(line.substr(start));
    return ans;
}

int32_t main() {
    string s = "1 2 3 4 5";
    vector<string> vs = split(s);
    for (auto s : vs) cout << s << endl;

    return 0;
}

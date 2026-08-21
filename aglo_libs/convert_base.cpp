
int charToVal(char c) {
    if ('0' <= c and c <= '9') return c - '0';
    return toupper(c) - 'A' + 10;
}

char valToChar(int val) {
    if (val < 10) return val + '0';
    return val - 10 + 'A';
}

string convertBase(string s, int a, int b) {
    auto fn0 = s.find_first_not_of('0');
    if (fn0 == string::npos) return "0";
    s = s.substr(fn0);
    string ans = "";

    while (!s.empty()) {
        int r = 0;
        string next_s = "";
        bool lead_zero = true;

        for (auto& c : s) {
            int cur = a * r + charToVal(c);
            int q = cur / b;
            r = cur % b;
            if (q > 0) lead_zero = false;
            if (!lead_zero) {
                next_s += valToChar(q);
            }
        }
        ans += valToChar(r);
        s = next_s;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

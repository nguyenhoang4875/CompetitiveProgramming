istream& operator>>(istream& is, __int128& x) {
    string s;
    is >> s;
    x = 0;
    bool neg = (s[0] == '-');
    for (int i = neg; i < (int)s.size(); i++) x = x * 10 + (s[i] - '0');
    if (neg) x = -x;
    return is;
}

ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) os << x / 10;
    return os << (char)('0' + x % 10);
}

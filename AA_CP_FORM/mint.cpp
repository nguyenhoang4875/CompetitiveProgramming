#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % mod) { v += (v < 0) * mod; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= mod) a.v -= mod;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += mod;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, mod - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

int32_t main() {
    mi a = 123;
    mi b = 123;
    // 123 ^ 123 % mod = 921450052
    cout << (int) pow(a, (int) b) << '\n';
}



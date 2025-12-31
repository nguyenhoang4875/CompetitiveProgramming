#include <bits/stdc++.h>

using namespace std;

#define el '\n'

void logarit() {
    // exp power
    cout << exp(1) << el;  // exp(1) = e, exp(2) = e * e, ...

    // logarit
    // base e
    cout << log(exp(2)) << el;  // logrit base e of (e ^2 )  = 2
    cout << log(10) << el;      // logarit base e of 10 = 2.30259

    // base 2
    cout << log2(4) << el;  // 2 (2 * 2 = 4)

    // base 10
    cout << log10(1000) << el;  // 3 (10 * 10 * 10 = 1000)

    // calculate log base a of b: loga(b) calcuate indirect by use log base e
    cout << (log(81) / log(3)) << el;  // 4 ( 3 * 3 * 3 * 3 = 81) log3(81) = 4

    // calculate number digit
    cout << (int)floor(1 + log10((double)1234)) << el;   // 4
    cout << (int)floor(1 + log10((double)10000)) << el;  // 5

    // Calculate n-th root of a:
    cout << pow((double)8, (double)1.0 / (double)3) << el;  // 2: 2 * 2 * 2 = 8
    cout << exp(log((double)8) * 1.0 / (double)3) << el;    // 2: 2 * 2 * 2 = 8
}

void pointDistance() {
    int dx = 3, dy = 4, dz = 12;
    // 2D points : hypot(dx, dy) = sqrt((dx * dx) + (dy * dy))
    double d2 = hypot(dx, dy);
    cout << d2 << el;  // 5

    // 3D points: hypot(dx, dy, dz) = sqrt((dx * dx) + (dy * dy) + (dz * dz))
    double d3 = hypot(dx, dy, dz);
    cout << d3 << el;  // 13
}

void solve() {
    cout << "Logarit: " << el;
    logarit();
    cout << "Points Distance: " << el;
    pointDistance();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// FFT implementation (Cooley–Tukey, in-place, iterative)
using cd = complex<double>;
const double PI = acos(-1);

// Perform FFT or inverse FFT on vector 'a'
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    static vector<int> rev;
    static vector<cd> roots{0,1};
    if ((int)rev.size() != n) {
        int k = __builtin_ctz(n);
        rev.assign(n,0);
        for(int i=0;i<n;i++)
            rev[i] = (rev[i>>1]>>1) | ((i&1)<<(k-1));
    }
    for(int i=0;i<n;i++){
        if(i<rev[i]) swap(a[i], a[rev[i]]);
    }
    if ((int)roots.size() < n) {
        // compute roots up to n
        roots.resize(n);
        for (int k = 1; k < n; k <<= 1) {
            double angle = PI / k;
            cd w = polar(1.0, angle);
            for (int i = k; i < 2*k; i++) {
                roots[i] = (i&1) ? roots[i/2] * w : roots[i/2];
            }
        }
    }
    for (int len = 1; len < n; len <<= 1) {
        for (int i = 0; i < n; i += 2*len) {
            for (int j = 0; j < len; j++) {
                cd u = a[i+j];
                cd v = a[i+j+len] * roots[len+j];
                a[i+j] = u+v;
                a[i+j+len] = u-v;
            }
        }
    }
    if (invert) {
        reverse(a.begin()+1, a.end());
        for (cd & x : a)
            x /= n;
    }
}

// Multiply two polynomials A and B, returning C = A*B
vector<cd> fftMultiply(vector<cd> const& A, vector<cd> const& B) {
    int n = 1;
    int need = (int)A.size() + (int)B.size() - 1;
    while (n < need) n <<= 1;
    vector<cd> fa(A.begin(), A.end()), fb(B.begin(), B.end());
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    fa.resize(need);
    return fa;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int maxa = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }

    // Maximum possible sum
    int S = maxa * k;
    // Find FFT length
    int N = 1;
    while (N <= S) N <<= 1;
    N <<= 1;  // zero-padding for safe convolution

    // Build base polynomial F(x) = sum_{i=1..n} x^{a[i]}
    vector<cd> base(N);
    for (int x : a)
        base[x] += 1.0;

    // Binary exponentiation of polynomial to k-th power
    auto polyPow = [&](vector<cd> poly, int exp) {
        vector<cd> result(N);
        result[0] = 1.0;  // polynomial "1"
        while (exp > 0) {
            if (exp & 1) {
                result = fftMultiply(result, poly);
                if ((int)result.size() > N)
                    result.resize(N);
            }
            poly = fftMultiply(poly, poly);
            if ((int)poly.size() > N)
                poly.resize(N);
            exp >>= 1;
        }
        // Ensure size at least S+1
        if ((int)result.size() < S+1)
            result.resize(S+1);
        return result;
    };

    vector<cd> C = polyPow(base, k);

    // Extract and print all achievable sums s with coefficient > 0
    bool first = true;
    for (int s = 0; s <= S && s < (int)C.size(); s++) {
        int cnt = int(round(real(C[s])));
        if (cnt > 0) {
            if (!first) cout << ' ';
            cout << s;
            first = false;
        }
    }
    cout << "\n";
    return 0;
}

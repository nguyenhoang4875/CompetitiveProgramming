# Gauss Elimination (Giải hệ phương trình tuyến tính)

## 🎯 Mục tiêu
Giải hệ phương trình tuyến tính:

\[
\begin{cases}
a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n = b_1 \\
a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n = b_2 \\
\vdots \\
a_{n1}x_1 + a_{n2}x_2 + \dots + a_{nn}x_n = b_n \\
\end{cases}
\]

Sử dụng **phép biến đổi sơ cấp trên hàng (Elementary Row Operations)** để đưa ma trận về dạng bậc thang và giải bằng **quay lui (back-substitution)**.

---

## 🔧 Kỹ thuật cơ bản

### 3 phép biến đổi sơ cấp:
1. Hoán đổi hai hàng.
2. Nhân một hàng với một hằng số khác 0.
3. Cộng một bội số của một hàng vào hàng khác.

---

## 🧮 Cài đặt C++ tổng quát

```cpp
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

// Trả về:
// 0 = vô nghiệm, 1 = nghiệm duy nhất, 2 = vô số nghiệm
int gauss(vector<vector<double>> a, vector<double> &x) {
    int n = (int)a.size();        // số phương trình
    int m = (int)a[0].size() - 1; // số ẩn (cột cuối là hệ số tự do)
    vector<int> where(m, -1);
    x.assign(m, 0);

    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row + 1; i < n; ++i)
            if (fabs(a[i][col]) > fabs(a[sel][col]))
                sel = i;
        if (fabs(a[sel][col]) < EPS)
            continue;
        swap(a[sel], a[row]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            x[i] = a[where[i]][m] / a[where[i]][i];

    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += x[j] * a[i][j];
        if (fabs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
}
```

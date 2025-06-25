# Binary Gauss Elimination (Trường nhị phân GF(2))

## 🎯 Bài toán

Cho một ma trận nhị phân kích thước `n x n` chứa các ký tự `0`, `1` và `?`.
Hãy gán `0` hoặc `1` cho các dấu `?` sao cho:

* XOR mỗi hàng = 0
* XOR mỗi cột = 0

---

## 📝 Problem Summary

### PROBLEM SUMMARY:

* **Task**: Ma trận `n × n` gồm `0`, `1`, `?`. Đếm số cách điền `?` sao cho **mỗi hàng và mỗi cột có số lượng số 1 chẵn** (tức là XOR = 0).
* **Input**:

  * Số nguyên `n (1 ≤ n ≤ 20)`
  * Ma trận `n × n` với mỗi ô là `'0'`, `'1'` hoặc `'?'`
* **Output**:

  * In ra số cách điền dấu `?` thỏa mãn yêu cầu, modulo `mod`

### Constraints:

* `n ≤ 20`
* Tổng số dấu `?` ≤ 400

### Time/Space:

* Complexity chấp nhận được: `O(n³)` với Gauss nhị phân

---

## 🔑 Key Ideas

* Mỗi dấu `?` là một biến nhị phân `xi ∈ {0, 1}`
* Mỗi hàng/cột cho một phương trình XOR = 0
* Hệ phương trình trên trường nhị phân GF(2)
* Dùng **Gauss Elimination** để khử và tính số nghiệm

---

## 🚀 Approach

### Mô hình bài toán thành hệ phương trình:

* Gán biến cho mỗi dấu `?`
* Với mỗi hàng/cột, lập phương trình XOR của các biến và các số `1` đã biết
* Tổng cộng có `2n` phương trình (n hàng + n cột)
* Hệ có dạng: `Ax = b (mod 2)`

### Gauss Elimination:

* Áp dụng Gauss Elimination trên GF(2)
* Nếu hệ vô nghiệm → In ra `0`
* Nếu hệ có nghiệm → Số cách = `2^(số biến tự do)`

---

## ⚠️ Edge Cases

* Không có dấu `?` nào → chỉ cần kiểm tra tổng XOR các hàng và cột
* Hệ chứa dòng `0 = 1` → vô nghiệm
* Tất cả là `?` → nghiệm rất nhiều (`2^(n^2 - (2n - rank))`)

---

## 🧮 Biểu diễn hệ phương trình

* Mỗi `?` là một biến nhị phân `xi ∈ {0, 1}`
* Hệ được biểu diễn thành ma trận `bitset`:

  * `f[i][j] = 1` nếu biến `xj` xuất hiện trong phương trình thứ `i`
  * `f[i][cntVar]` là giá trị vế phải (RHS)

## ⚙️ Gauss Elimination (trên GF(2))

```cpp
int gauss(int nVar, vector<bitset<MAX_VAR>>& f) {
    int row = 0;         // dòng hiện tại đang xử lý (pivot)
    int m = f.size();    // tổng số phương trình (số dòng)

    for (int col = 0; col < nVar && row < m; ++col) {
        int sel = -1;
        for (int i = row; i < m; ++i) {
            if (f[i][col]) {
                sel = i;
                break;
            }
        }
        if (sel == -1) continue;
        swap(f[sel], f[row]);

        for (int i = 0; i < m; ++i) {
            if (i != row && f[i][col]) {
                f[i] ^= f[row];
            }
        }
        ++row;
    }

    for (int i = row; i < m; i++) {
        if (f[i][nVar]) return -1; // 0 = 1 → vô nghiệm
    }

    return nVar - row; // số biến tự do
}
```

## 📄 Kết quả

* Nếu hệ vô nghiệm → In ra `0`
* Nếu hệ hữu nghiệm → Số cách gán = `2^(số biến tự do)`

---

## 🧐 Ví dụ đơn giản

### Input:

```
? 0
0 ?
```

### Biến:

* x0 = a\[1]\[1]
* x1 = a\[2]\[2]

### Phương trình:

* Row 1: x0 = 0
* Row 2: x1 = 0
* Col 1: x0 = 0
* Col 2: x1 = 0

### Gauss kết luận:

* Hệ có đúng 1 nghiệm: x0 = 0, x1 = 0

## 💡 Lưu ý

* Phép cộng và trừ trên GF(2) đều là XOR.
* `bitset` rất hiệu quả cho cỡ biến nhỏ (n ≤ 100).
* Gauss trên GF(2) giản lược hơn rất nhiều so với trường thực.


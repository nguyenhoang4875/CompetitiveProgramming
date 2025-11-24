Avoid handle float, double
=> Try to convert or make it to int (long long)

Set $x$ number after the comma(',') in double
```C++
    cout << fixed << setprecision(8);
```
Or
```C++
    cout << fixed;
    cout.precision(8);
```

**Calculate the Euclid distance:**
**2D points**: hypot(dx, dy) = sqrt((dx * dx) + (dy * dy))
``` C++
    hypot(dx, dy)
```

**3D points**: hypot(dx, dy, dz) = sqrt((dx * dx) + (dy * dy) + (dz * dz))
``` C++
    hypot(dx, dy, dz)
```

**Count for interval ranges**

Given array a and b size m
```C++
    1 <= n, m <= 1e5 
    1 <= a[i] <= b[i] <= 1e5 
```
from: a[i] to b[i] will do task size: $x$

Calculate $cnt[x]: x = 1 -> n$ in $O(n)$ time?

Solution:
- for each pair a[i], b[i]: ```cnt[a[i]] += x; cnt[b[i + 1]] -= x;```
- calculate prefix sum of cnt: ```cnt[i] += cnt[i - 1]```

**Modulo base-index 1**
```C++
int modIdx1(int i, int n) {
    return ((i - 1) % n + n) % n + 1;
}
```
Way to solve a problem:

PROBLEM SUMMARY:
- Task: [Mô tả ngắn gọn nhiệm vụ]
- Input: [Format input]
- Output: [Format output] 
- Constraints: [Giới hạn quan trọng]
- Time/Space: [Độ phức tạp yêu cầu]

KEY OBSERVATIONS:
- [Điểm quan trọng 1]
- [Điểm quan trọng 2]

APPROACH:
- [Thuật toán/phương pháp]
- [Các bước chính]

EDGE CASES:
- [Trường hợp đặc biệt]



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



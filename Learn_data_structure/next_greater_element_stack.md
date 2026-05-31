# Monotonic Stack: Next/Prev Greater/Smaller

This version uses a monotonic stack of **indices** (`vector<int> st;`) with **0-based indexing**.
It makes it easy to compute nearest greater / smaller elements on both sides, and also compute the `[l[i], r[i]]` range where `a[i]` stays the strict max/min.

Notes:
- The code uses `<=` / `>=` in the pop condition, so the neighbor is **strictly greater** / **strictly smaller**.
- If you need duplicate-safe tie-breaking for **subarray min/max counting**, use asymmetric comparisons.

Example tie-breaking (common CP pattern):
- For maximum contribution: previous uses `<`, next uses `<=`.
- For minimum contribution: previous uses `>`, next uses `>=`.

## Next/Prev Greater (strict)

### Previous greater index (nearest greater to the left)

```cpp
// 0-based array a[0..n-1]
vector<int> st;
for (int i = 0; i < n; i++) {
    while (st.size() && a[st.back()] <= a[i]) st.pop_back();
    prevGreater[i] = st.size() ? st.back() : -1; // -1 = none
    st.push_back(i);
}
```

### Next greater index (nearest greater to the right)

```cpp
st.clear();
for (int i = n - 1; i >= 0; i--) {
    while (st.size() && a[st.back()] <= a[i]) st.pop_back();
    nextGreater[i] = st.size() ? st.back() : -1; // -1 = none
    st.push_back(i);
}
```

## Next/Prev Smaller (strict) ("next lesser")

Just flip the comparison:

```cpp
// previous smaller
st.clear();
for (int i = 0; i < n; i++) {
    while (st.size() && a[st.back()] >= a[i]) st.pop_back();
    prevSmaller[i] = st.size() ? st.back() : -1;
    st.push_back(i);
}

// next smaller
st.clear();
for (int i = n - 1; i >= 0; i--) {
    while (st.size() && a[st.back()] >= a[i]) st.pop_back();
    nextSmaller[i] = st.size() ? st.back() : -1;
    st.push_back(i);
}
```

## Convert index -> value

```cpp
nextGreaterVal[i] = (nextGreater[i] != -1 ? a[nextGreater[i]] : -1);
nextSmallerVal[i] = (nextSmaller[i] != -1 ? a[nextSmaller[i]] : -1);
```

## Range [l[i], r[i]] where a[i] is strict max/min

This matches the pattern in your snippet:

### Strict maximum range

```cpp
// lMax[i] = prevGreater[i] + 1 (or 0)
// rMax[i] = nextGreater[i] - 1 (or n-1)
lMax[i] = (prevGreater[i] != -1 ? prevGreater[i] + 1 : 0);
rMax[i] = (nextGreater[i] != -1 ? nextGreater[i] - 1 : n - 1);
```

### Strict minimum range

```cpp
// lMin[i] = prevSmaller[i] + 1 (or 0)
// rMin[i] = nextSmaller[i] - 1 (or n-1)
lMin[i] = (prevSmaller[i] != -1 ? prevSmaller[i] + 1 : 0);
rMin[i] = (nextSmaller[i] != -1 ? nextSmaller[i] - 1 : n - 1);
```

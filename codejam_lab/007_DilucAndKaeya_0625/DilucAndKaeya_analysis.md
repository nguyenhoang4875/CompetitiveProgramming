# Problem Summary

## Task  
For each prefix of a string consisting of `'D'` and `'K'`, count how many segments can be formed such that each segment has the same ratio of D to K as the entire prefix.

## Input
- Integer `t`: number of test cases  
- For each test case:  
  - Integer `n`: length of the string  
  - String `s`: consisting of `n` characters, each either `'D'` or `'K'`

## Output
- For each test case, print `n` space-separated integers — the number of equal-ratio segments ending at each prefix.

## Constraints
- `1 ≤ t ≤ 1000`  
- `1 ≤ n ≤ 5 * 10^5`  
- Sum of all `n` over all test cases ≤ `5 * 10^5`

## Time/Space
- **Time**: O(n) per test case  
- **Space**: O(n) per test case

---

# Key Ideas
- Normalize D:K ratios using **GCD** to compare segments efficiently  
- Use a map to **count how many times each ratio** has appeared so far

---

# Property

If two segments have the same D:K ratio `a:b`, then their concatenation also has the same ratio:

\[
\frac{a}{b} = \frac{c}{d} \Rightarrow \frac{a + c}{b + d} = \frac{a}{b}
\]

This property guarantees that consecutive pieces with the same ratio can be combined while maintaining the same ratio,  
justifying the counting of ratio occurrences with a map.

---

# Approach

- Track counts of `'D'` and `'K'` while scanning the prefix  
- Reduce `(D, K)` to simplest form by dividing both by `gcd(D, K)`  
- Map the simplified pair `(d, k)` to number of times it has occurred  
- The answer for prefix `i` is the count of this ratio so far

---

# Edge Cases
- Prefix contains only `'D'` or only `'K'`  
- Ratios that reduce to the same simplest form (e.g. `2:2 → 1:1`)  
- Long repeated sequen

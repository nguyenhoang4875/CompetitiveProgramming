# Number Theory


## 1. Greatest common divisor
## Prove 1: $\gcd(a, b) = \gcd(a, a - b)$

Assume $a > b$ else $swap(a, b)$

$\gcd(a, b) = \gcd(a, a - b)$

Case 1: $\gcd(a, b) > \gcd(a, a - b)$
Assume $d = \gcd(a, b)$
=> $ a = x * d, b = y * d$
=> $ a - b = (x - y) * d$
So: $\gcd(a, a - b) = \gcd(x * d, (x - y) * d) = d $
=> Case 1 is wrong

Case 2: $\gcd(a, b) < \gcd(a, a - b)$
Assume $d = \gcd(a, a - b)$
=> $ a = x * d, (a - b) = y * d$
=> $ b = (x - y) * d$
So: $\gcd(a, b) = \gcd(x * d, (x - y) * d) = d $
=> Case 2 is wrong
```C++
while (a > b) a -= b;
// after that
a = a % b;
```
=> $\gcd(a, b) = \gcd(a, a - b) = \gcd(b, a \% b)$

### Gcd multiple number
=> $\gcd(a, b, c) = \gcd(a, a - b, a - c)$
=> $\gcd(a_1, a_2, ..., a_n) = \gcd(a_1, a_1 - a_2,..., a_1 - a_n)$


## Prove 2: $a \% b < a / 2$
if a > b:
$a \% b < a / 2$

Case 1: $ b > a / 2 $ => $a \% b = a - b < a - a / 2 = a / 2 $
Case 2: $ b <= a / 2 $ => $a \% b < b < a / 2 $


## 2. Square root 
Safe square root for n:
```C++
    long long sq = sqrtl(n + 5)
    while(sq * sq < n) sq--;
```
sqrt usually has lots of **precision issues** and unpredictable behavior. In general, for solving $\sqrt n$ you can use this reliably:

 For large values of $N$ the constant ($5$) shouldn't affect the runtime much, the point is just to slightly raise the output enough to avoid situations where sqrt() gives a lower value than intended (e.g. $49.9999$ instead of $50.0001$), which would give the wrong result when casting to an integer.


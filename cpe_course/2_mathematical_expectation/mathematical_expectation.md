# Mathematical Expectation

## Linearity of Expectation

$E[x1 + x2] = E[x1] + E[x2]$

Example: 
Dice two dices 6-sides:
What is expected value:
$E[x1 + x2] = E[x1] + E[x2] = 3.5 + 3. 5 = 7$

What is the expected number of coin flips to get a head?

$ x = \sum xi * p(xi)$

$x = (1 + x) / 2 + 1/2$
$<=> 2 * x = (1 + x) + 1$
$<=> x = 2$

TH1: T* 
TH2: H
What is the expected number of coin flips to get two consecutive heads?

$x = 1 / 2 * (x + 1) + 1/2^2*(x + 2) + 1/2^2 * 2$
$<=> 4 * x = 2 *(x + 1) + x + 2 + 2 $
$<=> x = 6$
TH2: T*
TH3: TT*
TH1: HH

What is the expected number of coin flips to get $n$ consecutive heads?

$x = 1/2 * (x + 1) + 1/2^2 *(x + 2) + ... + 1/2^n *(x + n) + 1/2^n *n $
$<=> x = x (1/2 + 1/4 + ... + 1/2^n) + 1/2 + 2/4 + .. n/2^n + n/2^n$
$<=> x = 2^{n+1} - 2 $

Example: $n = 2 => x = 2^3 - 2 = 6$

## Theorem 1
If the probability of success of a Bernaulli trial is p
then the expected number of trails to get a success is $1/p$

## Theorem 2
If probability of getting success in Bernaulli trail is p,
then expected number of successes in n trails in $n*p$


### Coupon Collector Problem
A certain brand distributes a coupon a packet of chips.
The coupon is chosen randomly from a set of $n$ distinct coupons.
What is the expected number of packets one must buy so that
you get all $n$ distinct coupons.

$E[x_i]$ : Denotes the number of packs to grab $i-th$ new coupon

$E[x] = E[x_1 + x_2 + ... + x_n]$
$E[x] = E[x_1] + E[x_2] + ... + E[x_n]$

Prob of getting i-th new coupon = (available new coupons) / total coupon = (n - (i - 1)) / n
=> p = (n - i + 1) / n
=> $E[x_i] = 1/p = n /(n - i + 1)$

$E[x] = n/n + n/(n - 1) + ... + n$
$E[x] = n * (1 + 1/2 + 1/3 + ... + 1/n)$



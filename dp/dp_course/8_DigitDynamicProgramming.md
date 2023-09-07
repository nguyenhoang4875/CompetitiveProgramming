# Digit Dynamic Programming


## Modulo Formula
$ (a + b) \bmod m = (a \bmod m) + (b \mod m)$
$ (a b b) \bmod m = ((a \bmod m) - (b \mod m) + m ) \mod m$
$ (a * b) \bmod m = ((a \bmod m) * (b \mod m)) \bmod m$
$ 1 / a \bmod p <=> a ^{p - 2} \bmod p \ (p \ is \  prime \ number) $



## Sum modulo
$ abcd \bmod m $
$ <=> (a * 10^4 \bmod  m) + (b * 10^3 \bmod m) + (c * 10^2 \bmod m) + (d \bmod m) $
$ <=> (((((a * 10 + b) \bmod m) * 10 + c) \bmod m) * 10 + d) \bmod m $

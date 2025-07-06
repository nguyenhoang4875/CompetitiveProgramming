# Modular Multiplicative Group Theory

## 1. Definitions

### Euler's Totient Function

* $\varphi(n)$: the number of integers $a \in [1, n-1]$ such that $\gcd(a, n) = 1$.
* These $a$'s form the **multiplicative group modulo $n$**, denoted $\mathbb{Z}_n^*$.

### Multiplicative Group Modulo $n$: $\mathbb{Z}_n^*$

* Defined as: $\{ a \in [1, n-1] \mid \gcd(a, n) = 1 \}$
* Operation: multiplication modulo $n$
* $|\mathbb{Z}_n^*| = \varphi(n)$
* This group is:

  * Closed under multiplication modulo $n$
  * Has identity element $1$
  * Every element has a multiplicative inverse modulo $n$
  * Associative and (commutative): it's an abelian group

## 2. Product of All Elements in $\mathbb{Z}_n^*$

Let $G = \mathbb{Z}_n^*$. Then:

* $P = \prod_{a \in G} a \mod n$
* $P \equiv 1 \mod n$ or $P \equiv -1 \mod n$

### When is $P = -1 \mod n$?

* This happens **if and only if** $G$ has exactly **one non-trivial element of order 2**, i.e., some $x \ne 1$ such that:

  $$
  x^2 \equiv 1 \mod n
  $$

* Examples:

  * $\mathbb{Z}_7^* = \{1,2,3,4,5,6\}$:
    $\prod = 720 \mod 7 = -1$ → because 6 is the only element $\ne 1$ with $x^2 \equiv 1 \mod 7$

### Otherwise

* If there are multiple elements of order 2 or none, $P \equiv 1 \mod n$

## 3. Theoretical Foundations

### Group Theory (Abstract Algebra)

* $\mathbb{Z}_n^*$ is a finite abelian group.
* Product of all elements in a finite abelian group:

  * If every element can be paired with its inverse (except the identity), and the number of order-2 elements is even, then total product = 1.
  * If there is exactly one element of order 2 (besides identity), then total product = -1.

### Wilson's Theorem (special case for primes)

* If $p$ is a prime:

  $$
  (p-1)! \equiv -1 \mod p
  $$

  → So $\prod_{a \in \mathbb{Z}_p^*} a = -1 \mod p$

### Proof (Sketch) for General Finite Abelian Group

Let $G$ be a finite abelian group. Every element $a \in G$ has a unique inverse $a^{-1} \in G$ such that:

$$
    a \cdot a^{-1} = 1
$$

Now:

* Identity $1$ is its own inverse.
* Elements with order greater than 2 can be grouped into pairs $(a, a^{-1})$ such that $a \ne a^{-1}$ and $a \cdot a^{-1} = 1$.
* Elements with order exactly 2 satisfy $a^2 = 1$, so $a = a^{-1}$.

Let $S \subset G$ be the set of all elements of order 2 (including 1).
Then:

* Product of all $a \in G$:

$$
\prod_{a \in G} a = \prod_{a \in S} a
$$

* If $|S|$ is odd, the product = -1
* If $|S|$ is even, the product = 1

Thus, the product is $-1 \mod n$ if and only if there is exactly one non-identity element of order 2.

### Why the inverse of an element is also in $\mathbb{Z}_n^*$

Let $x \in \mathbb{Z}_n^*$, so $\gcd(x, n) = 1$. Then by Bézout's identity, there exist integers $y, k$ such that:

$$
    x \cdot y + n \cdot k = 1 \Rightarrow x \cdot y \equiv 1 \mod n
$$

Define $y' = y \mod n$. Then:

* $x \cdot y' \equiv 1 \mod n$
* Suppose for contradiction that $\gcd(y', n) = d > 1$: then $d \mid y'$ and $d \mid n$
* From $x \cdot y' \equiv 1 \mod n$, we get $x \cdot y' = 1 + kn \Rightarrow d \mid 1$
* But $d > 1 \Rightarrow d \mid 1$ is impossible

$\Rightarrow$ So $\gcd(y', n) = 1$, and $y' \in \mathbb{Z}_n^*$. Hence, the inverse of any element in $\mathbb{Z}_n^*$ is also in $\mathbb{Z}_n^*$.

## 4. Application in Problem Solving

* In problems like finding the largest subsequence with product $\equiv 1 \mod n$:

  * Consider all $a \in \mathbb{Z}_n^*$
  * Compute the product $P$
  * If $P \equiv 1$, use all
  * If $P \ne 1$, remove the element $= P \mod n$, so the rest multiply to 1

## 5. Notes on Negative Modulo

* $-1 \mod n = n - 1$
* Modular arithmetic always yields result in range $[0, n-1]$

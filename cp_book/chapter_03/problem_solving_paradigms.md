# Problem Solving Paradigms

## Complete Search:
#### A problem is possibly a Complete Search problem if the problem:

- Asks to print all answers and the solution space can be as big as the search space,
- Has small search space (the total operations in the worst case is < 100M),
- Has suspiciously large time limit constraint and has lots of (early) pruning potentials,
- Can be pre-calculated,
- Is a known NP-hard/complete problem without any special property
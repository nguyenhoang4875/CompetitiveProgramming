# Policy based data structures

**code requires**
```C++
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
```
**Super power API**
Same with set/map and have two function with $O(log(n))$:
- **order_of_key (k)**: return number of items **strictly** smaller than $k$.
- **find_by_order(k)**: returns to an **iterator** to the $k-th$ element (counting from zero)

## Ordered Set (indexed set)
### Default ascending order by key
```C++
template <class key, class cmp = less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag,
                         tree_order_statistics_node_update>;
ordered_set<int> s;
```
### Descending order by key
```C++
ordered_set<int, greater<int>> s;
```
## Ordered Map (indexed map)
### Default ascending order by key
```C++
template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
ordered_map<int, int> my_map;
```
### Descending order by key
```C++
ordered_map<int, int, greater<int>> my_map;
```

## Ordered Multiple Set (indexed multiple set)
### Default ascending order by key
Based on **ordered_set** then use **pair<key, int>** for **duplicate key** => multiple_set
```C++
template <class key, class cmp = less<pair<key, int>>>
using ordered_multiset = tree<pair<key, int>, null_type, cmp, rb_tree_tag,
                              tree_order_statistics_node_update>;
ordered_multiset<int> s;
```
Insert to ordered_multiset
```C++
int t = 0;
s.insert({1, t++});
s.insert({1, t++});
s.insert({2, t++});
```
Find by order
```C++
s.find_by_order(val) 
```
Order of key
```C++
s.order_of_key({i, 0}) 
```
Get iterator of key by using lower_bound
```C++
s.lower_bound({i, 0}) 
```
Erase a key
```C++
s.erase(s.lower_bound({i, 0}));
```

### Descending order by key
```C++
ordered_multiset<int, greater<pair<int, int>>> s;
```

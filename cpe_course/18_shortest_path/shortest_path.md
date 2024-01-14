# Shortest Path Algorithm

## Dijkstra Algorithm
- Shortest path one node to other nodes
- Weight Graphs
- Only for positive edges
- Greedy approach
TC: $O((V + E) * log E)$
MC: $O(V + E)$

## Bellman Ford Algorithm
- Shortest path one node to other nodes
- Works with negative edges
- Can detect negative cycle, with extra step
### Terms
1. Init dist[vertices] = oo, dist[src] = 0
2. Relax all edges $V - 1$ times **most important**
3. Negative Weight Cycle Detection
TC: $O(V * E)$
MC: $O(V * E)$

## Floyd Warshall Algorithm
- All pair shortest path
- Shortest between all pair of vertices
- Works with negative edges
- Can detect negative cycle, with extra step
TC: $O(V ^ 3)$
MC: $O(V ^ 3)$
 

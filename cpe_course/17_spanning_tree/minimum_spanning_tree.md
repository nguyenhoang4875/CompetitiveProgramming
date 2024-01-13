# Minimum Spanning Tree

## Prim's MST Algorithm
- Weighted Undirected Graph
- Greedy Algorithm

### Terms
MST set = []
Active Edge = edge from a vertex in in MST set to V
MST Edge = and edge that has been included in the MST so far

### Algorithm
1. Start from any Source vertex
2. Out of all active edges, pick the one with **smallest weight**.
   - select in Y in MST
   - add edges starting from Y in the active edges list

## Kruskal MST Algorithm
- Greedy Algorithm
- Store graph as a edge list
- DSU for detecting cycle
- O(E * logV)
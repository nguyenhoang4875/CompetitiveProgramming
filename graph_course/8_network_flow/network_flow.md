# Network flow

A flow network is defined as a directed involving a source(S) and a sink(T)
and several other nodes connected with edges. Each edge has an individual capacity
which is the maximum limit of flow that edge could allow.
- Source and sink nodes.
- Edges have capacity. Flow in every edge is between that capacity.
- Total flow out of the source is equal to total flow in the sink.

## Maximum Flow
It is defined as the maximum amount of flow that the network would allow to flow from source to sink.

## Residual Graph and Augmenting Paths
- The residual network has the same vertices as the original network, and one or two edges for each in the original.
More specifically, if the flow along the edge x-y is less than the capacity there is forward edge x-y with capacity
equal to the different between the capacity and the flow (this is called the residual capacity),
and if the flow is positive there is backward y-x with a capacity equal to the flow on x-y.

- An augmenting path is simply a path from the source to the sink in the residual network,
whose purpose is to increase the flow in the original one. It is important to understand that
the edges in this path can point the "wrong way" according to the original network.

- The path capacity of a path is the minimum capacity of an edge along path.
It is also call the bottleneck value

## Ford Fulkerson (FFA)
### Pseudo Code of Ford Fulkerson Algorithm

1. Initial flow in all edges to be zero
2. While (there is an augmenting path between source and sink in the residual graph):
   - Augment the flow between Source and Sink along the path.
   - Update Residual Network
- The algorithm is guaranteed to terminate: due to the capacities and flow of edges being integer
and the path-capacity being positive, at each step we get a new flow that is closer to the maximum
- As a side note, the algorithm isn't guaranteed to even terminate if the capacities are irrationals.
- It is obvious that in a network in which a maximum flow has been found there is no augmenting path,
otherwise we would be able to increase the maximum value of the flow.
- The complexity of FFA can not be accurately computed as it all depends on the path from source to sink.
It can be estimated to be **O(max_flow * E)**.
- If we use BFS instead of DFS, this algorithm covert to Edmond-Karp algorithm **O(V * E^2)**

## Dinic's Algorithm

- Dinic includes construction of level graphs and residual graphs and finding of augmenting paths adding with blocking flow.
- Level graph is one where value of each node is its shortest distance from source in the residual graph.
This graph contains edges which have positive flow in them. Update of level graph 
includes removal of edges with full capacity. Removal of nodes that are not sink and are dead end.
- Blocking flow includes finding the new path from the bottleneck node.
- Complexity of Dinic algorithms is **O(E * V^2)**

Pseudo Code of Dinic's Algorithms
1. Initial flow in all edges to be zero
2. Construct Level Graph
3. While (sink node is reachable from source node in the level graph)
   - While (there is an augmenting path between source and sink in the residual graph):
     - Find blocking flow in the level graph
     - Add blocking flow in the total flow
     - Update Residual Network
   - Go to step #2



















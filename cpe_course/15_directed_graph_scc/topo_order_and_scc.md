# Topological Order and Strongly Connected Components

## Topological Order
- Topological sorting for Directed Acyclic Graph(DAG) is a liner ordering of vertices such that for every directed edge U V, vertex U comes before V in the order. Topological Sorting for a graph is not possible if the graph is not a DAG
- Topological Order: You have to **number the vertices** so that every edge leads from the vertex with a smaller number assigned to the vertex with a large one.
- In other words, you want to find a permutation of the vertices (**topological order**) which corresponds to the order defined by all edges of the graph.
- Topological oder ca be **non-unique**.
- Topological order is **not exist** at all if the graph contains cycles.
- There is difference between DFS and Topological Ordering.

## Terms and properties of Topological Order
- Finish Time: time when we leave the node if DFS
- For any two nodes u and v, if there is an edge from u -> v, finish time of u will be higher than finish time of v.

## Strongly Connected Components
**Connectivity** in an undirected graph means that every vertex can reach every other vertex via any path. If the graph is not connected the graph can be broken down into **Connected Components**.

**Strong Connectivity** applies only to directed graphs. A directed graph is strongly connected if there is a directed path from any vertex to every other vertex.

**Condensed Component Graph** is a DAG in which every node is a **Strongly Connected Component** and edges are between nodes if there is an edge from one of the nodes of these SCC in original graph

- **Source**: Node with no incoming edges.
- **Sink**: Node with no outgoing edges.
There will be no cycle/SCC in new condensed component graph.

1. Topological sort G, first node in will be source node
2. Start iterating from the beginning and perform a dfs in reverse graph
3. Mark all the nodes visited as one strongly connected component(SCC)

**Source** node **in Graph** is **Sink node** in **Reverse Graph**


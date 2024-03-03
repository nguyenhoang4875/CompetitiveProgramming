# Articulation Points and Bridges

## Articulation Points
A vertex V in connected graph is an articulation point if and only if
 **deletion of vertex V together with all edges incident to V**
 disconnects the graph into **two or more non empty components**

**Discovered Time**:
Time which the current node was discovered during the DFS

**Lowest Time**:
It is the discovered time of a node, to which we can traverse, by using at most one backed edges in current subtree


## Bridges
An edge in connected graph if and only if **removing it disconnects the graph**
# Tree

## 1.Tree vs Graph
**Tree** is a connected graph which has no cycles
Every pair of vertices have **exactly one path** between them

Tree has n nodes, it has n - 1 edges

**Forest** has multiple trees

## 2. Leaf, child, parent, root, subtree, ancestors, LCA and other key terms in trees.

1. Root: The topmost node in a tree. It is the starting point for traversing the tree.

2. Node: A fundamental part of a tree that contains data and may have references (pointers or links) to other nodes.

3. Parent: A node in a tree that has one or more child nodes.

4. Child: A node in a tree that has a parent node.

5. Leaf: A node in a tree that has no children, i.e., it is a node without any descendants.

6. Ancestor: Any node that is on the path from the root to the node in question, excluding the node itself.

7. Subtree: A tree formed by a node and its descendants, including the node itself.

8. Depth: The level or distance of a node from the root. The root has a depth of 0, its children have a depth of 1, and so on.

9. Height: The length of the longest path from a node to a leaf. The height of the tree is the height of the root.

10. Siblings: Nodes with the same parent are called siblings.

11. Binary Tree: A special type of tree in which each node has at most two children, referred to as the left child and the right child.

## 3. DFS on trees

### 3.1 DFS on tree without using visited array.
Properties of DFS
 - Using vector parent to trace ancestor to avoid a cycles when dfs:
    ```C++
    void dfs(int cur, int par) {
        parent[cur] = par;
        for (auto x : gr[cur]) {
            if (x != par) {
                dfs(x, cur);
            }
        }
    }
    ```
### 3.2 DFS Tree and Backedges

Tree obtained after performing a Depth First Search on graph

cycle
articulation points and bridges

Backedges denotes cycle in the graph

## 4. Lowest Common Ancestor(LCA)

- A vertex V that lies on the path from the root to v1 and the path from the root to v2, and the vertex should be the lowest
- LCA is the most bottom ancestor of v1 and v2
- LCA lies on the shortest path from v1 to v2
- For all path related problems we use LCA
- LCA using two pointers
- LCA using Euler tour
- LCA using binary lifting
  


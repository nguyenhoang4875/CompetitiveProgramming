
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int sum = 0;
    void dfs(TreeNode *root) {
        if (root->right != NULL) dfs(root->right);
        sum += root->val;
        root->val = sum;
        if (root->left != NULL) dfs(root->left);
    }

    TreeNode *bstToGst(TreeNode *root) {
        if(root == NULL) return root;
        dfs(root);
        return root;
    }
};
#include<bits/stdc++.h>

/**
 * Binary Search Tree
 * a binary tree in which for each node:
 *  value of all nodes left subtree << all nodes right subtree
 * 
*/
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
    // BstNode(int _data) {
    //     data = _data;
    //     left = NULL;
    //     right = NULL;
    // };
};

BstNode* newNode(int data) {
    BstNode* node = new BstNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BstNode* insert(BstNode* root, int data) {
    if(root == NULL) {
        root = newNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bool search(BstNode* root, int data) {
    if(root == NULL) return false;
    if(root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else return search(root->right, data);
}

// same for findMax
int findMin(BstNode* root) {
    if(root == NULL) -1;
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// same for findMaxRecursion
int findMinRecursion(BstNode* root) {
    if(root == NULL) -1;
    if(root->left == NULL) return root->data;
    return findMinRecursion(root->left);
}

// find height of a binary tree
int findHeight(BstNode* root) {
    if(root == NULL) return 0;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void printCurrentLevel(BstNode* root, int level) {
    if(root == NULL) return;
    if(level == 1) {
        cout << root->data << " ";
        return;
    }
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
}

int sumCurrentLevel(BstNode* root, int level) {
    if(root == NULL) return 0;
    if(level == 1) return root->data;
    return sumCurrentLevel(root->left, level - 1) + sumCurrentLevel(root->right, level -1);

}

void printSumLevelOrder(BstNode* root) {
    int h = findHeight(root);
    for (int i = 1; i <= h; i++) {
        cout << "level = " << i << endl;;
        cout << "sum = " <<  sumCurrentLevel(root, i) << endl;
    }
}

// Traversal using BFS
void printLevelOrder(BstNode* root) {
    int h = findHeight(root);
    for (int i = 1; i <= h; i++) {
        printCurrentLevel(root, i);
    }
}

// LevelOrder BFS
void levelOrder(BstNode* root) {
    if(root == NULL) return;
    queue<BstNode*> q;
    q.push(root);
    while (!q.empty()) {
        BstNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if(current-> left != NULL) q.push(current->left);
        if(current-> right!= NULL) q.push(current->right);
    }
}

// Traversal using DFS: preOrder, inOrder, postOrder
void preOrder(BstNode* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(BstNode* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(BstNode* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {

    BstNode* root = NULL;
    root = insert(root, 25);
    root = insert(root, 15);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 22);
    root = insert(root, 35);
    root = insert(root, 70);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 18);
    root = insert(root, 24);
    root = insert(root, 31);
    root = insert(root, 44);
    root = insert(root, 66);
    root = insert(root, 90);


    cout << "InOrder: " << endl;
    inOrder(root);
    cout << "\npreOrder: " << endl;
    preOrder(root);
    cout << "\npostOrder: " << endl;
    postOrder(root);

    cout <<endl;
    cout <<"Search element" << endl;
    // find value 18 
    cout <<"18 = " << search(root, 18) << endl; // true
    // find value 55 // true
    cout << "55 = " << search(root, 55) << endl; // false
    cout << "Find min of BST" << endl;
    cout << "min = " << findMin(root) << endl;;
    cout << "min recursion = " << findMinRecursion(root) << endl;

    cout << "find height of the tree" << endl;
    cout << "height = " << findHeight(root) << endl;

    cout << "traversal bsf" << endl;
    printLevelOrder(root);
    cout << endl;
    cout << "traversal bsf level order" << endl;
    levelOrder(root);

    printSumLevelOrder(root);



    return 0;
}
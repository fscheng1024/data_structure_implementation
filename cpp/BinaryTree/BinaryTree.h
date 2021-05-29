#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <vector>

class TreeNode {
private:
    int value;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode() : value(0), left(nullptr), right(nullptr) {};
    TreeNode(int a) : value(a), left(nullptr), right(nullptr) {};

    friend class BinaryTree;
};


class BinaryTree {
private:
    TreeNode* root;
    bool isLeaf(TreeNode* root);
    int heightHelper(TreeNode* root);
    int minHelper(TreeNode* root);
    int minBSTHelper(TreeNode* root);
    bool equalsHelper(TreeNode* root1, TreeNode* root2);
    bool isValidBSTHelper(TreeNode* root, int min_val, int max_val);
    void getNodesAtKDistHelper(TreeNode* root, int k, std::vector<int>* result);

public:
    BinaryTree() : root(nullptr) {};
    void insert(int value);
    bool find(int value);
    void levelOrderTraversal();
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int height();
    int min();
    bool equals(BinaryTree* other);
    bool isValidBST();
    std::vector<int>* getNodesAtKDist(int k);

};

#endif
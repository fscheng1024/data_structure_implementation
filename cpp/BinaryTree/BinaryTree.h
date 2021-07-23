#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include <iostream>
#include <vector>

class TreeNode {
    friend class BinaryTree;
private:
    int value;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode() : value(0), left(nullptr), right(nullptr) {};
    TreeNode(int a) : value(a), left(nullptr), right(nullptr) {};
};


class BinaryTree {
    
private:
    TreeNode* root;
    
    bool isLeaf(TreeNode* root);
    bool containsHelper(TreeNode* root, int value);
    int heightHelper(TreeNode* root);
    int minHelper(TreeNode* root);
    int maxHelper(TreeNode* root);
    int minBSTHelper(TreeNode* root);
    bool equalsHelper(TreeNode* root1, TreeNode* root2);
    bool isValidBSTHelper(TreeNode* root, int min_val, int max_val);
    void getNodesAtKDistHelper(TreeNode* root, int k, std::vector<int>* result);
    std::vector<int> levelorder(TreeNode* root);
    std::vector<int> preorder(TreeNode* root);
    std::vector<int> inorder(TreeNode* root);
    std::vector<int> postorder(TreeNode* root);
    int sizeHelper(TreeNode* root);
    int countLeavesHelper(TreeNode* root);
    bool areSiblingsHelper(TreeNode* root, int first, int second);
    bool getAncestorsHelper(TreeNode* root, int value, std::vector<int>* result);
    void getSuccessorPredecessorHelper(
        TreeNode* root, TreeNode* predecessor, TreeNode* successor, 
        int value, std::vector<int>* result
    );
    TreeNode* moveRootTo(TreeNode* root, int value);
    TreeNode* getLeftMost(TreeNode *current);
    TreeNode* getRightMost(TreeNode *current);
    TreeNode* getSuccessorHelper(TreeNode* root, int value);
    TreeNode* getPredecessorHelper(TreeNode* root, int value);
    TreeNode* deleteNodeHelper(TreeNode* root, int value);

public:
    BinaryTree() : root(nullptr) {};
    void insert(int value);
    bool find(int value);
    bool contains(int value);
    void levelOrderTraversal();
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    int height();
    int min();
    int max();
    int size();
    bool equals(BinaryTree* other);
    bool isValidBST();
    std::vector<int>* getNodesAtKDist(int k);
    int countLeaves();
    bool areSiblings(int first, int second);
    std::vector<int>* getAncestors(int value);
    std::vector<int>* getSuccessorPredecessor(int value);
    int getSuccessor(int data);
    int getPredecessor(int data);
    void deleteNode(int value);
};

#endif
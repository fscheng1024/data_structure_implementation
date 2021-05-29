#ifndef _TREENODE_H_
#define _TREENODE_H_
#include <iostream>

class TreeNode {
private:
    int value;
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode(int a) : value(a), left(nullptr), right(nullptr) {};

    friend class BinaryTree;
};

#endif
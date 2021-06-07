#include <iostream>
#include <stack>
#include "BinaryTree.h"


bool BinaryTree::isLeaf(TreeNode* root) {
    return root->left == nullptr && root->right == nullptr;
}


void BinaryTree::insert(int value) {
    TreeNode* node = new TreeNode(value);
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    TreeNode* current = root;
    while (true) {
        if (value < current->value) {
            if (!current->left) {
                current->left = node;
                break;
            }
            current = current->left;
        } else {
            if (!current->right) {
                current->right = node;
                break;
            }
            current = current->right;
        }
    }
}


bool BinaryTree::find(int value) {
    TreeNode* current = root;
    while(current) {
        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } else
            return true;
    }
    return false;
}


// == height ==
int BinaryTree::height() {
    return BinaryTree::heightHelper(root);
}


int BinaryTree::heightHelper(TreeNode* root) {
    if (isLeaf(root)) return 0;
    return 1 + std::max(heightHelper(root->left), heightHelper(root->right));
}


// == min ==
int BinaryTree::min() {
    // return minBSTHelper(root);
    return minHelper(root);
}


int BinaryTree::minBSTHelper(TreeNode* root) {
    if (!root) return -1;

    TreeNode* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->value;
}


int BinaryTree::minHelper(TreeNode* root) {
    if (isLeaf(root)) return root->value;

    int left = minHelper(root->left);
    int right = minHelper(root->right);

    return std::min(std::min(left, right), root->value);
}


// == Traversal ==
void BinaryTree::levelOrderTraversal() {  
    std::vector<int> result;
    if (!root) return;

    for (int i=0 ; i <= height(); i++) {
        std::vector<int>* tmp = getNodesAtKDist(i);
        for (int i=0; i<tmp->size(); i++) {
            result.push_back(tmp->at(i));
        }
    }
    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
}


void BinaryTree::preOrderTraversal() {
    std::vector<int> result;
    if (!root) return;

    std::stack<TreeNode *> todo;
    todo.push(root);
    while (!todo.empty()) {
        TreeNode* node = todo.top();
        todo.pop();
        result.push_back(node->value);
        if (node->right) 
            todo.push(node->right);
        if (node->left) 
            todo.push(node->left);
    }

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
}


void BinaryTree::inOrderTraversal() {
    std::vector<int> result;
    if (!root) return;

    std::stack<TreeNode *> todo;
    TreeNode* current = root;
    while (current || !todo.empty()) {
        while (current) {
            todo.push(current);
            current = current->left;
        }
        TreeNode* node = todo.top();
        todo.pop();
        result.push_back(node->value);
        current = node->right; 
    }

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";
}


void BinaryTree::postOrderTraversal() {
    std::vector<int> result;
    if (!root) return;

    std::stack<TreeNode *> todo;
    todo.push(root);
    while (!todo.empty()) {
        TreeNode* current = todo.top();
        if (!current->left && !current->right) {
            todo.pop();
            result.push_back(current->value);
        }
        if (current->left) {
            todo.push(current->left);
            current->left = nullptr;
        }
        if (current->right) {
            todo.push(current->right);
            current->right = nullptr;
        }
    }

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << "\n";

}


// == equals ==
bool BinaryTree::equals(BinaryTree* other) {
    if (!other) return false;
    return equalsHelper(root, other->root);
}


bool BinaryTree::equalsHelper(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2) return true;

    if ((!root1 && root2) || (root1 && !root2)) return false;
    if (root1->value != root2->value) return false;

    return equalsHelper(root1->left, root2->left) && equalsHelper(root1->right, root2->right);

}


// == isValidBST ==
bool BinaryTree::isValidBST() {
    if (!root) return true;

    return isValidBSTHelper(root, INT_MIN, INT_MIN);
}


bool BinaryTree::isValidBSTHelper(TreeNode* root, int min_val, int max_val) {
    if (!root) return true;

    if ((root->value < min_val) || (root->value > max_val)) return false;

    return isValidBSTHelper(root->left, min_val, root->value - 1) 
            && isValidBSTHelper(root->right, root->value + 1, max_val);
}


// == getNodesAtKDist ==
std::vector<int>* BinaryTree::getNodesAtKDist(int distance) {
    std::vector<int>* result = new std::vector<int>;
    getNodesAtKDistHelper(root, distance, result);
    return result;
}


void BinaryTree::getNodesAtKDistHelper(TreeNode* root, int distance, std::vector<int>* result) {
    if (!root) return;
    if (distance < 0) return;

    if (distance == 0) {
        result->push_back(root->value);
        return;
    }
    getNodesAtKDistHelper(root->left, distance-1, result);
    getNodesAtKDistHelper(root->right, distance-1, result);
}
#include "AVLTree.h"

bool AVLTree::isLeaf(AVLNode* root) {
    return root->left == nullptr && root->right == nullptr;
}

AVLNode* AVLTree::insertHelper(AVLNode* root, int value) {
    if (!root) {
        return new AVLNode(value);
    }

    if (value < root->value) {
        root->left = insertHelper(root->left, value);
    }
    if (value > root->value) {
        root->right = insertHelper(root->right, value);
    }
    return root;
}

void AVLTree::insert(int value) {
    root = insertHelper(root, value);

    return;
}


int AVLTree::getHeightHelper(AVLNode* root) {
    if (!root) return -1;
    if (isLeaf(root)) return 0;

    return 1 + std::max(
                    getHeightHelper(root->left), 
                    getHeightHelper(root->right));
}


int AVLTree::getHeight() {
    return getHeightHelper(root);
}


bool AVLTree::isLeftHeavy(AVLNode* root) {
    std:: cout << "isLeftHeavy" << endl;
    return balanceFactor(root) > 1;
}


bool AVLTree::isRightHeavy(AVLNode* root) {
    std:: cout << "isRightHeavy" << endl;
    return balanceFactor(root) < -1;
}


int AVLTree::balanceFactor(AVLNode* root) {
    if (!root) return 0;
    return getHeightHelper(root->left) - getHeightHelper(root->right);
}
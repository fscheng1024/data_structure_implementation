#include <iostream>
#include <stack>
#include "BinaryTree.h"

void printVec(std::vector<int> input) {
    for (int i=0; i<input.size(); ++i)
        std::cout << input[i] << " ";
    std::cout << "\n";
}


bool BinaryTree::isLeaf(TreeNode* root) {
    return root->left == nullptr && root->right == nullptr;
}


void BinaryTree::insert(int value) {
    TreeNode* node = new TreeNode(value);
    if (!root) {                            // if tree is empty
        root = new TreeNode(value);
        return;
    }

    TreeNode* current = root;
    while (true) {
        if (value < current->value) {       
            if (!current->left) {           // current node did not has left child
                current->left = node;
                break;
            }
            current = current->left;
        }
        else {
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
    while (current) {
        if (value < current->value) {
            current = current->left;
        }
        else if (value > current->value) {
            current = current->right;
        }
        return true;
    }
    return false;
}

// == contains ==
bool BinaryTree::contains(int value) {
    return containsHelper(root, value);
}

bool BinaryTree::containsHelper(TreeNode* root, int value) {
    if (!root) return false;
    if (root->value == value) return true;

    return containsHelper(root->left, value) || containsHelper(root->right, value);
}


// == size ==
int BinaryTree::size() {
    return sizeHelper(root);
}

int BinaryTree::sizeHelper(TreeNode* root) {
    if (!root) return 0;
    if (isLeaf(root)) return 1;

    return 1 + sizeHelper(root->left) + sizeHelper(root->right);
}


// == countLeaves ==
int BinaryTree::countLeaves() {
    return countLeavesHelper(root);
}

int BinaryTree::countLeavesHelper(TreeNode* root) {
    if (!root) return 0;
    if (isLeaf(root)) return 1;

    return countLeavesHelper(root->left) + countLeavesHelper(root->right);
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

// == max ==
int BinaryTree::max() {
    return maxHelper(root);
}

int BinaryTree::maxHelper(TreeNode* root) {
    if (isLeaf(root)) return root->value;

    int left = maxHelper(root->left);
    int right = maxHelper(root->right);

    return std::max(std::max(left, right), root->value);
}


// == Level-order Traversal ==
std::vector<int> BinaryTree::levelorder(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    for (int i = 0; i <= height(); i++) {
        std::vector<int>* tmp = getNodesAtKDist(i);
        for (int i = 0; i < tmp->size(); i++) {
            result.push_back(tmp->at(i));
        }
    }

    return result;
}

void BinaryTree::levelOrderTraversal() {
    std::vector<int> result = levelorder(root);
    printVec(result);
}


// == Pre-order Traversal ==
std::vector<int> BinaryTree::preorder(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    TreeNode* current = root;
    std::stack<TreeNode*> todo;     // create a stack to store visit
    todo.push(current);
    while (!todo.empty()) {
        TreeNode* node = todo.top();
        todo.pop();
        result.push_back(node->value);
        if (node->right)
            todo.push(node->right);
        if (node->left)
            todo.push(node->left);
    }
    return result;
}


void BinaryTree::preOrderTraversal() {
    std::vector<int> result = preorder(root);
    printVec(result);
}

// == In-order Traversal ==
std::vector<int> BinaryTree::inorder(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> todo;
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
    return result;
}

void BinaryTree::inOrderTraversal() {
    std::vector<int> result = inorder(root);
    printVec(result);
}

// == Post-order Traversal ==
std::vector<int> BinaryTree::postorder(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;

    std::stack<TreeNode*> todo;

    TreeNode* node = root;
    todo.push(node);
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
    return result;
}

void BinaryTree::postOrderTraversal() {
    std::vector<int> result = postorder(root);
    printVec(result);
}


// == equals ==
bool BinaryTree::equals(BinaryTree* otherTree) {
    if (!otherTree) return false;
    return equalsHelper(root, otherTree->root);
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


void BinaryTree::getNodesAtKDistHelper(
    TreeNode* root, int distance, std::vector<int>* result) {
    if (!root) return;
    if (distance < 0) return;

    if (distance == 0) {
        result->push_back(root->value);
        return;
    }
    getNodesAtKDistHelper(root->left, distance - 1, result);
    getNodesAtKDistHelper(root->right, distance - 1, result);
}

// are siblings ==
bool BinaryTree::areSiblings(int first, int second) {
    return areSiblingsHelper(root, first, second);
}

bool BinaryTree::areSiblingsHelper(TreeNode* root, int first, int second) {
    if (!root) return false;

    bool areSibling = false;
    if (root->left && root->right) {
        areSibling = (root->left->value == first && root->right->value == second) ||
            (root->left->value == second && root->right->value == first);
    }

    return areSibling ||
        areSiblingsHelper(root->left, first, second) ||
        areSiblingsHelper(root->right, first, second);
}


std::vector<int>* BinaryTree::getAncestors(int value) {
    std::vector<int>* result = new std::vector<int>;
    getAncestorsHelper(root, value, result);

    return result;
}

bool BinaryTree::getAncestorsHelper(TreeNode* root, int value, std::vector<int>* result) {
    if (!root) return false;
    if (root->value == value) return true;
    if (getAncestorsHelper(root->left, value, result) ||
        getAncestorsHelper(root->right, value, result)) {
        result->push_back(root->value);
        return true;
    }
    return false;
}

std::vector<int>* BinaryTree::getSuccessorPredecessor(int value) {
    std::vector<int>* result = new std::vector<int>;
    getSuccessorPredecessorHelper(root, nullptr, nullptr, value, result);

    return result;
}

void BinaryTree::getSuccessorPredecessorHelper(
    TreeNode* root, TreeNode* predecessor, TreeNode* successor,
    int value, std::vector<int>* result) {
    if (!root) return;

    if (root->value == value) {
        if (root->left) {
            TreeNode* node = root->left;
            while (node->right) {
                node = node->right;
            }
            predecessor = node;
            result->push_back(predecessor->value);
        }
        if (root->right) {
            TreeNode* node = root->right;
            while (node->left) {
                node = node->left;
            }
            successor = node;
            result->push_back(successor->value);
        }
        return;
    }
    if (root->value > value) {
        successor = root;
        result->push_back(successor->value);
        getSuccessorPredecessorHelper(root->left, predecessor, successor, value, result);
    }
    else if (root->value < value) {
        predecessor = root;
        result->push_back(predecessor->value);
        getSuccessorPredecessorHelper(root->right, predecessor, successor, value, result);
    }
}

TreeNode* BinaryTree::moveRootTo(TreeNode* root, int value) {
    if (!root) return nullptr;
    else if (root->value == value) return root;
    else if (root->value < value) return moveRootTo(root->right, value);
    else return moveRootTo(root->left, value);
}


TreeNode* BinaryTree::getLeftMost(TreeNode* current) {
    while (current->left) {
        current = current->left;
    }
    return current;
}

int BinaryTree::getSuccessor(int value) {
    TreeNode* successor = getSuccessorHelper(root, value);
    return successor->value;
}

TreeNode* BinaryTree::getSuccessorHelper(TreeNode* root, int value) {
    // Search the Node - O(h)
    TreeNode* current = moveRootTo(root, value);
    if (!current) return nullptr;

    //Case 1: Node has right subtree
    if (current->right) {
        return getLeftMost(current->right); // O(h)
    }
    //Case 2: No right subtree  - O(h)
    else {
        TreeNode* successor = nullptr;
        TreeNode* ancestor = root;
        while (ancestor != current) {
            if (current->value < ancestor->value) {
                successor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        if (!successor) {
            std::cout << "No successor Found\n";
            return nullptr;
        }
        return successor;
    }
}

TreeNode* BinaryTree::getRightMost(TreeNode* current) {
    while (current->right) {
        current = current->right;
    }
    return current;
}

int BinaryTree::getPredecessor(int value) {
    TreeNode* predecessor = getPredecessorHelper(root, value);
    return predecessor->value;
}

TreeNode* BinaryTree::getPredecessorHelper(TreeNode* root, int value) {
    // Search the Node - O(h)
    TreeNode* current = moveRootTo(root, value);
    if (!current) return nullptr;

    //Case 1: Node has left subtree
    if (current->left) {
        return getRightMost(current->left); // O(h)
    }

    //Case 2: No left subtree  - O(h)
    else {
        TreeNode* predecessor = nullptr;
        TreeNode* ancestor = root;
        while (ancestor != current) {
            if (current->value < ancestor->value) {
                //predecessor = ancestor; // so far this is the deepest node for which current node is in left
                ancestor = ancestor->left;
            }
            else {
                predecessor = ancestor;
                ancestor = ancestor->right;
            }
        }
        if (!predecessor) {
            std::cout << "No predecessor Found\n";
            return nullptr;
        }
        return predecessor;
    }
}

void BinaryTree::deleteNode(int value) {
    root = deleteNodeHelper(root, value);
}


TreeNode* BinaryTree::deleteNodeHelper(TreeNode* root, int value) {
    if (root == NULL) return root;
    else if (value < root->value)
        root->left = deleteNodeHelper(root->left, value);
    else if (value > root->value)
        root->right = deleteNodeHelper(root->right, value);

    else {
        // Case 1:  No child
        if (isLeaf(root)) {
            delete root;
            root = NULL;
        }
        //Case 2: One child 
        else if (root->left == NULL) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else {
            TreeNode* temp = getLeftMost(root->right);
            root->value = temp->value;
            root->right = deleteNodeHelper(root->right, temp->value);
        }
    }
    return root;

}
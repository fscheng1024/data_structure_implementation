#include <iostream>

using namespace std;

class AVLNode {
    friend class AVLTree;

    private:
        int value;
        AVLNode* left;
        AVLNode* right;
    
    public:
        AVLNode() :
            value(0), left(nullptr), right(nullptr) {};
        AVLNode(int x) :
            value(x), left(nullptr), right(nullptr) {};
};


class AVLTree {
    private:
        AVLNode* root;
        AVLNode* insertHelper(AVLNode* root, int value);
        int getHeightHelper(AVLNode* root);
        bool isLeaf(AVLNode* root);
        bool isLeftHeavy(AVLNode* root);
        bool isRightHeavy(AVLNode* root);
        int balanceFactor(AVLNode* root);

    public:
        void insert(int value);
        int getHeight();

};
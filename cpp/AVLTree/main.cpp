#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
    AVLTree* tree = new AVLTree();

    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    cout << tree->getHeight() << endl;
}
#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->insert(7);
    tree->insert(4); 
    tree->insert(9); 
    tree->insert(1); 
    tree->insert(6); 
    tree->insert(8); 
    tree->insert(10);

    //tree->levelOrderTraversal();
    //tree->preOrderTraversal();
    //tree->inOrderTraversal();
    tree->postOrderTraversal();
    

    BinaryTree* tree2 = new BinaryTree();
    tree2->insert(7);
    tree2->insert(4); 
    tree2->insert(9); 
    tree2->insert(1); 
    tree2->insert(6); 
    tree2->insert(8); 
    tree2->insert(11);
    
    std::cout << std::boolalpha << tree->find(10) << std::endl;
    std::cout << std::boolalpha << tree->find(11) << std::endl;
    std::cout << tree->height() << std::endl;
    std::cout << tree->min() << std::endl;
    std::cout << std::boolalpha << tree->equals(tree2) << std::endl;

    std::vector<int>* result = new std::vector<int>;
    result = tree->getNodesAtKDist(2);

    for (int i = 0; i < result->size(); ++i) {
        std::cout << result->at(i) << " ";
    }
    std::cout << "\n";

    return 0;

}
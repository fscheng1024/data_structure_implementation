#include <iostream>
#include <string>
#include <vector>

#include "BinaryTree.h"

using namespace std;

int main() {
    BinaryTree* tree = new BinaryTree();
    tree->insert(7);
    tree->insert(4); 
    tree->insert(9); 
    tree->insert(1); 
    tree->insert(6); 
    tree->insert(8); 
    tree->insert(10);

    tree->levelOrderTraversal();
    //tree->deleteNode(4);
    //tree->levelOrderTraversal();

    int value = 6;
    std::vector<int>* ancestors = tree->getAncestors(value);
    cout << "ancestors: ";
    for (int i = 0; i < ancestors->size(); ++i) {
        std::cout << ancestors->at(i) << " ";
    }
    std::cout << "\n";

    std::cout << "getSuccessor(" << std::to_string(value) << "): " << tree->getSuccessor(value) << std::endl;
    std::cout << "getPredecessor(" << std::to_string(value) << "): " << tree->getPredecessor(value) << std::endl;

 
    // tree->preOrderTraversal();
    // tree->inOrderTraversal();
    // tree->postOrderTraversal();
    
    std::cout << std::boolalpha << "find(10): " << tree->find(10) << std::endl;
    std::cout << std::boolalpha << "find(11): " << tree->find(11) << std::endl;
    std::cout << "tree->height(): " << tree->height() << std::endl;
    std::cout << "tree->min(): " << tree->min() << std::endl;

    std::vector<int>* result = new std::vector<int>;
    result = tree->getNodesAtKDist(2);
    std::cout << "At dist 2: ";
    for (int i = 0; i < result->size(); ++i) {
        std::cout << result->at(i) << " ";
    }
    std::cout << "\n";
    std::cout << "leaves: " << tree->countLeaves() << std::endl;
    std::cout << std::boolalpha << "areSiblings(1, 6): " << tree->areSiblings(1, 6) << std::endl;

    BinaryTree* tree2 = new BinaryTree();
    tree2->insert(7);
    tree2->insert(4); 
    tree2->insert(9); 
    tree2->insert(1); 
    tree2->insert(6); 
    tree2->insert(8); 
    tree2->insert(10);
    std::cout << std::boolalpha << "tree == tree2: " << tree->equals(tree2) << std::endl;

    return 0;

}
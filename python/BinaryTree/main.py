from BinaryTree import BinaryTree

tree = BinaryTree()
tree.insert(7)
tree.insert(4) 
tree.insert(9) 
tree.insert(1) 
tree.insert(6) 
tree.insert(8) 
tree.insert(10)

tree2 = BinaryTree()
tree2.insert(7)
tree2.insert(4) 
tree2.insert(9) 
tree2.insert(1) 
tree2.insert(6) 
tree2.insert(8) 
tree2.insert(10)

print(tree.is_valid())
print(tree.is_same(tree2))
print(tree.get_nodes_at_K_dist(2))
print(tree.get_height())

print(tree.levelorder_traversal())
print(tree.preorder_traversal())
print(tree.inorder_traversal())
print(tree.postorder_traversal())

class Node:
    def __init__(self, value):
        self._value = value
        self._left = None
        self._right = None;
    

class BinaryTree:
    def __init__(self):
        self.root = None
    
    def __is_leaf(self, root):
        return root._left == None and root._right == None
    
    def __get_height_helper(self, root):
        if self.__is_leaf(root): return 0
        
        return 1 + max(
            self.__get_height_helper(root._left), self.__get_height_helper(root._right))
    
    def __preorder(self, root):
        result = []
        if not root: return
        
        todo = []
        todo.append(root)
        while(todo):
            current = todo[-1]
            todo.pop()
            result.append(current._value)
            if current._right:
                todo.append(current._right)
            if current._left:
                todo.append(current._left)
                
        return result
    
    def __inorder(self, root):
        result = []
        if not root: return
        
        todo = []
        current = root
        while(current or todo):
            while(current):
                todo.append(current)
                current = current._left
            node = todo[-1]
            todo.pop()
            result.append(node._value)
            current = node._right
            
        return result
    
    def __postorder(self, root):
        result = []
        if not root: return
        
        todo = []
        todo.append(root)
        while (todo):
            current = todo[-1]
            if not current._left and not current._right:
                todo.pop()
                result.append(current._value)
                
            if current._right:
                todo.append(current._right)
                current._right = None
                
            if current._left:
                todo.append(current._left)
                current._left = None
                
        return result
    
    def __levelorder(self, root):
        if not root: return 
        result = []
        for i in range(self.get_height()+1):
            result += self.get_nodes_at_K_dist(i)
            
        return result
            
    def __is_same_helper(self, root1, root2):
        if not root1 and not root2: 
            return True
        
        if (not root1 and root2) or (root1 and not root2):
            return False
        
        if root1._value != root2._value:
            return False
        
        return self.__is_same_helper(root1._left, root2._left) and self.__is_same_helper(root1._right, root2._right)
        
    def __is_valid_helper(self, root, min_val, max_val):
        if not root: return True
        if root._value < min_val or root._value > max_val:
            return False
        
        return self.__is_valid_helper(root._left, min_val, root._value-1) and self.__is_valid_helper(root._right, root._value+1, max_val)
    
    def __get_nodes_at_K_dist_helper(self, root, distance, result):
        if not root: return
        if distance == 0:
            result.append(root._value)
            return
        
        self.__get_nodes_at_K_dist_helper(root._left, distance-1, result)
        self.__get_nodes_at_K_dist_helper(root._right, distance-1, result)
        
    def insert(self, value):
        node = Node(value)
        if not self.root:
            self.root = Node(value)
            return
        
        current = self.root
        while(True):
            if value < current._value:
                if not current._left:
                    current._left = node
                    break
                current = current._left
            else:
                if not current._right:
                    current._right = node
                    break
                current = current._right
            
    def find(self, value):
        current = self.root
        while(current):
            if value < current._value:
                current = current._left
            elif value > current._value:
                current = current._right
            else:
                return True
        return False
    
    def get_height(self):
        return self.__get_height_helper(self.root)
    
    def preorder_traversal(self):
        return self.__preorder(self.root)
    
    def inorder_traversal(self):
        return self.__inorder(self.root)
        
    def postorder_traversal(self):
        return self.__postorder(self.root)
    
    def levelorder_traversal(self):
        return self.__levelorder(self.root)
    
    def is_same(self, other):
        if not other: return False
        return self.__is_same_helper(self.root, other.root)
    
    def is_valid(self):
        return self.__is_valid_helper(self.root, float("-inf"), float("inf"))
    
    def get_nodes_at_K_dist(self, distance):
        result = []
        self.__get_nodes_at_K_dist_helper(self.root, distance, result)
        
        return result


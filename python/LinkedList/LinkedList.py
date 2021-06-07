class Node:
    def __init__(self, value):
        #super().__init__()
        self.value = value
        self.next = None
    
    
class SingleLinkedList:
    def __init__(self):
        #super().__init__()
        self.head = None
        self.size = 0
    
    def __isEmpty(self):
        return self.size == 0
    
    def __isSingle(self):
        return self.size == 1
    
    def __contains(self, value):
        return self.indexOf(value) >= 0
    
    
    def __get_previous(self, node):
        current = self.head
        while current.next:
            if current.next == node:
                return current
            current = current.next
            
        return None
                
    
    def indexOf(self, value):
        current = self.head
        count = 0
        while current:
            if current.value == value:
                return count
            current = current.next
            count += 1
        return -1
            
            
    def print_out(self):
        current = self.head
        while current:
            print(current.value, end = " ")
            current = current.next
        print(" ")
        
        
    def add_first(self, value):
        node = Node(value)
        node.next = self.head
        self.head = node
        self.size += 1
    
    
    def add_last(self, value):
        node = Node(value)
        if self.__isEmpty():
            self.head = node
        else: 
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = node
        self.size += 1
        
        
    def delete_first(self):
        if self.__isEmpty():
            raise Exception ("List is empty!")
        else:  
            second = self.head.next
            self.head.next = None
            self.head = second
            
        
    def delete_last(self):
        if self.__isEmpty():
            raise Exception ("List is empty!")
        if self.__isSingle():
            self.head = None
        else:
            current = self.head
            while current.next:
                current = current.next
            previous = self.__get_previous(current)
            previous.next = None
            self.size -= 1
            
                
    def delete_at(self, index):
        if index < 0 or index > self.size:
            raise Exception ("Invalid index!!")
        
        count = 0        
        current = self.head
        while current:
            if count == index:
                previous = self.__get_previous(current)
                previous.next = current.next
                del current
                self.size -= 1
            else:
                current = current.next
                count += 1
       
                
    def delete_value(self, value):
        current = self.head
        while current:
            if current.value == value:
                previous = self.__get_previous(current)
                previous.next = current.next
                del current
                self.size -= 1
            else:
                current = current.next
        raise Exception ("There is no {} in the list!".format(value))
                
                
    def clear(self):
        while self.__isEmpty() == False:
            current = self.head
            self.head = self.head.next
            del current
            self.size -= 1
            
            
    def reverse(self):
        if (self.__isEmpty() or self.__isSingle()): return
    
        previous = None
        current = self.head 
        while(current): 
            forward = current.next
            current.next = previous 
            previous = current 
            current = forward
        self.head = previous
        
          
    def get_kth_from_end(self, k):
        slow = self.head
        current = self.head
        if(self.__isEmpty()): return -1
        for i in range(k-1):
            current = current.next
            if current is None:
                return -1
            
        fast = current
        while fast.next:
            fast = fast.next
            slow = slow.next
        
        return slow.value
            
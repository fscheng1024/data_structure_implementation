class Node:
    def __init__(self, value):
        super().__init__()
        self._value = value
        self._next = None
    
class SingleLinkedList:
    def __init__(self):
        super().__init__()
        self._head = None
        
    def print_out(self):
        current = self._head
        while (self._head is not None):
            print(self._head.value)
            current = current._next
            

list = SingleLinkedList()
list.head = Node("Mon")
e2 = Node("Tue")
e3 = Node("Wed")

# Link first Node to second node
list._head._next = e2

# Link second Node to third node
e2._next = e3

list.print_out()
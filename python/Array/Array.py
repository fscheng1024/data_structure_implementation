
class DynamicArray:
    def __init__(self):
        self.count = 0 
        self.capacity = 1 
        self.items = self.make_array(self.capacity) 
        
    
    def __resize(self):
        newItems = self.make_array(2 * self.capacity) 
          
        for i in range(self.count):  
            newItems[i] = self.items[i] 
              
        self.items = newItems  
        self.capacity = 2 * self.capacity 
        
        
    def __isFull(self):
        return self.count == self.capacity
    
    
    def __isEmpty(self):
        return self.count == 0
    
    
    def __size(self):
        return self.count
         
         
    def insert(self, item):
        if(self.__isFull()): self.__resize()
            
        self.items[self.count] = item  
        self.count += 1
    
    
    def insertAt(self, item, index):
        if index<0 or index>self.count:
            return -1
        if self.__isFull(): self.__resize()
        for i in range(self.count-1, index-1, -1):
            self.items[i+1] = self.items[i]
        self.items[index] = item
        self.count += 1
       
        
    def reverse(self):
        newItems = self.make_array(2 * self.capacity) 
        for i in range(self.count):
            newItems[i] = self.items[self.count - i - 1]
        
        self.items = newItems
    
    
    def max(self):
        max_num = 0
        for i in range(self.count):
            if self.items[i] > max_num:
                max_num = self.items[i]
        
        return max_num
    
    
    def remove(self):
        if self.__isEmpty():
            return -1
        self.items[self.count - 1] = 0
        self.count -= 1
    
    
    def removeAt(self, index):
        for i in range(index, self.count):
            self.items[i] = self.items[i+1]
        self.count -= 1
        
        
    def make_array(self, new_cap): 
        """ 
        Returns a new array with new_cap capacity 
        """ 
        return new_cap * [0] 
    
    
    def print_out(self):
        for i in range(self.count):
            print(self.items[i], end =" ")
        print(" ")


if __name__ == '__main__':
    arr = DynamicArray() 
    
    arr.insert(1) 
    arr.insert(2) 
    arr.insert(3) 
    arr.insert(4) 
    arr.insert(5) 
    arr.insertAt(6, 1) 
    
    arr.print_out()
    
    arr.reverse()
    arr.print_out()
    
    print(arr.max())
    
    arr.remove()
    arr.print_out()
    
    arr.removeAt(3)
    arr.print_out()

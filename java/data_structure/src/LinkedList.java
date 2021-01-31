import java.util.NoSuchElementException;

public class LinkedList {
    private class Node {
        private int value;
        private Node next;

        public Node(int value) {
            this.value = value;
        }
    }

    private Node first;
    private Node last;
    private int size;

    private boolean isEmpty() {
        return first == null;
    }

    private Node getPrevious(Node node) {
        var current = first;
        while(current != null) {
            if (current.next == node)
                return current;
            current = current.next;
        }
        return null;
    }

    public void print() {
        var current = first;
        if (isEmpty())
            throw new NoSuchElementException();

        while(current != null) {
            System.out.print(current.value + " ");
            current = current.next;
        }
        System.out.println("");

    }

    public void addFirst(int value) {
        var node = new Node(value);
        
        if (isEmpty()) {
            first = last = node;
        } else {
            node.next = first;
            first = node;
        }
        size++;
    }

    public void addLast(int value) {
        var node = new Node(value);
        
        if(isEmpty()) {
            first = last = node;
        } else {
            last.next = node;
            last = node;
        }
        size++;
    }

    public void deleteFirst() {
        if(isEmpty()) {
            throw new NoSuchElementException();
        }  
        if (first == last) 
            first = last = null;
        
        else {
            var second = first.next;
            first.next = null;
            first = second;
        }
        size--; 
    }

    public void deleteLast() {
        if(isEmpty()) {
            throw new NoSuchElementException();
        }  
        if (first == last) 
            first = last = null;
        else {
            var previous = getPrevious(last);
            last = previous;
            previous.next = null;
        }
        size--;
    }

    public boolean contains(int value) {
        return indexOf(value) != -1;
    }

    public int indexOf(int value) {
        int count = 0;
        var current = first;

        while(current != null) {
            if (current.value == value) {
                return count;
            }
            current = current.next;
            count++;
        }
        return -1;
    }
    
    public int size() {
        return size;
    }
 
    public int[] toArray() {
        int[] array = new int[size];
        var current = first;
        var index = 0;
        while(current != null) {
            array[index++] = current.value;
            current = current.next;
        }
        return array;
    }

    public void reverse() {
        if(isEmpty()) {
            return;
        }  
        var previous = first;
        var current = first.next;
        while(current != null) {
            var next = current.next;
            current.next = previous;
            previous = current;
            current = next; 
        }
        last = first;
        first.next = null;
        first = previous;
    }

    public int getKthFromEnd(int k) {
        if(isEmpty())
            throw new IllegalArgumentException();
             
        var slow = first;
        var current = first;
        for(int i=0; i<k-1; i++){
            current = current.next;
            if(current == null)
                throw new IllegalArgumentException();
        }

        var fast = current;
        while(fast != last) {
            fast = fast.next;
            slow = slow.next;
        } 
        return slow.value;
    }
}

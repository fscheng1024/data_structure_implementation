package LinkedList;

import java.util.Arrays;

//package myLinkedList;

public class Main {
    public static void main(String[] args) {
        var list = new LinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        list.addLast(50);
        // list.deleteFirst();
        // list.deleteLast();
        list.print();
        var array = list.toArray();
        System.out.println(Arrays.toString(array));

        System.out.println(list.size());
        System.out.println(list.indexOf(10));
        System.out.println(list.contains(10));

        System.out.println(list.getKthFromEnd(1));

        // list.reverse();
        // list.print();
    }
}

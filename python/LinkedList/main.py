from LinkedList import SingleLinkedList

items = SingleLinkedList()
items.add_first(1)
items.add_last(2)
items.add_last(3)
items.add_last(4)
items.add_last(5)

items.print_out()
print(items.indexOf(2))

items.delete_first()
items.print_out()

items.delete_last()
items.print_out()

items.reverse()
items.print_out()

print(items.get_kth_from_end(2))
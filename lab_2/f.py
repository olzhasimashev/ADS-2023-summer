class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def insert(self, data, position):
        new_node = Node(data)
        if position == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            current = self.head
            count = 0
            while current and count < position:
                if count == position - 1:
                    new_node.next = current.next
                    current.next = new_node
                current = current.next
                count += 1

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next

n = int(input())
linked_list = LinkedList()
for _ in range(n):
    data = int(input())
    node = Node(data)
    if linked_list.head is None:
        linked_list.head = node
    else:
        last_node = linked_list.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = node

data = int(input())
position = int(input())
linked_list.insert(data, position)
linked_list.print_list()
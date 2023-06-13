class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            curr = self.head
            while curr.next:
                curr = curr.next
            curr.next = Node(data)

    def display(self):
        elements = []
        curr_node = self.head
        while curr_node:
            elements.append(curr_node.data)
            curr_node = curr_node.next
        return ' '.join(elements)

def cyclic_shift(ll, k):
    if ll.head is None:
        return ll

    first = ll.head
    curr = ll.head
    while curr.next:
        curr = curr.next
    curr.next = first

    for _ in range(k):
        curr = curr.next

    ll.head = curr.next
    curr.next = None
    return ll

N, K = map(int, input().split())
words = input().split()

poem = LinkedList()
for word in words:
    poem.append(word)

poem = cyclic_shift(poem, K)
print(poem.display())
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

    def remove_second(self):
        curr = self.head
        while curr and curr.next:
            next_node = curr.next
            curr.next = next_node.next
            curr = next_node.next

    def display(self):
        elements = []
        curr_node = self.head
        while curr_node:
            elements.append(str(curr_node.data))
            curr_node = curr_node.next
        return ' '.join(elements)
    
N = int(input().strip())
data = list(map(int, input().strip().split()))

ll = LinkedList()
for item in data:
    ll.append(item)

ll.remove_second()
print(ll.display())
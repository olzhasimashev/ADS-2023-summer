class Node(object):
    def __init__(self, val=0, next=None):
        self.val : int = val
        self.next: Node = next

def insert(head: Node, node: Node, p: int):
    if p == 0:
        node.next = head
        return node
    else:
        current = head
        for _ in range(p - 1):
            current = current.next
        node.next = current.next
        current.next = node
        return head
    
def remove(head: Node, p: int):
    if p == 0:
        return head.next
    else:
        current = head
        for _ in range(p - 1):
            current = current.next
        current.next = current.next.next
        return head

def printAll(head: Node):
    if head is None:
        print("-1")
    else:
        current = head
        while current is not None:
            print(current.val, end=" ")
            current = current.next
        print()

def replace(head: Node, p1: int, p2: int):
    node = None
    if p1 == 0:
        node = head
        head = head.next
    else:
        current = head
        for _ in range(p1 - 1):
            current = current.next
        node = current.next
        current.next = node.next
    head = insert(head, node, p2)
    return head

def reverse(head: Node):
    previous = None
    current = head
    while current is not None:
        next_node = current.next
        current.next = previous
        previous = current
        current = next_node
    return previous

def cyclic_left(head: Node, x: int):
    if head is None or x == 0:
        return head
    else:
        current = head
        for _ in range(x - 1):
            current = current.next
        new_head = current.next
        current.next = None
        current = new_head
        while current.next is not None:
            current = current.next
        current.next = head
        return new_head

def cyclic_right(head: Node, x: int):
    if head is None or x == 0:
        return head
    else:
        length = 1
        current = head
        while current.next is not None:
            current = current.next
            length += 1
        current.next = head
        for _ in range(length - x):
            current = current.next
        new_head = current.next
        current.next = None
        return new_head

head: Node = None

while(True):
    vals = [int(i) for i in input().split()]
    if (vals[0] == 0):
        break
    elif (vals[0] == 1):
        head = insert(head, Node(vals[1]), vals[2])
    elif (vals[0] == 2):
        head = remove(head, vals[1])
    elif (vals[0] == 3):
        printAll(head)
    elif (vals[0] == 4):
        head = replace(head, vals[1], vals[2])
    elif (vals[0] == 5):
        head = reverse(head)
    elif (vals[0] == 6):
        head = cyclic_left(head, vals[1])
    elif (vals[0] == 7):
        head = cyclic_right(head, vals[1])
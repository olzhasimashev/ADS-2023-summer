class Node:
    def __init__(self, val):
        self.prev = None
        self.next = None
        self.val = val


head = None
tail = None


def add_back(s):
    global head, tail
    new_node = Node(s)
    if tail is None:
        head = tail = new_node
    else:
        tail.next = new_node
        new_node.prev = tail
        tail = new_node
    print("ok")


def add_front(s):
    global head, tail
    new_node = Node(s)
    if head is None:
        head = tail = new_node
    else:
        head.prev = new_node
        new_node.next = head
        head = new_node
    print("ok")


def empty():
    return head is None


def erase_front():
    global head, tail
    if head is None:
        print("error")
    else:
        print(head.val)
        head = head.next
        if head is None:
            tail = None
        else:
            head.prev = None


def erase_back():
    global tail, head
    if tail is None:
        print("error")
    else:
        print(tail.val)
        tail = tail.prev
        if tail is None:
            head = None
        else:
            tail.next = None


def front():
    if head is None:
        print("error")
    else:
        print(head.val)


def back():
    if tail is None:
        print("error")
    else:
        print(tail.val)


def clear():
    global head, tail
    head = None
    tail = None
    print("ok")


while True:
    s = input().split()
    command = s[0]
    if command == "add_front":
        add_front(s[1])
    elif command == "add_back":
        add_back(s[1])
    elif command == "erase_front":
        erase_front()
    elif command == "erase_back":
        erase_back()
    elif command == "front":
        front()
    elif command == "back":
        back()
    elif command == "clear":
        clear()
    elif command == "exit":
        print("goodbye")
        break
class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key

def insert(root, key):
    if root is None:
        return Node(key)
    else:
        if root.val < key:
            root.right = insert(root.right, key)
        else:
            root.left = insert(root.left, key)
    return root

def getSize(node):
    if node is None:
        return 0
    else:
        return 1 + getSize(node.left) + getSize(node.right)

def findSubtreeSize(root, value):
    if root is None:
        return 0
    elif root.val == value:
        return getSize(root)
    elif root.val < value:
        return findSubtreeSize(root.right, value)
    else:
        return findSubtreeSize(root.left, value)

n = int(input())
nodes = list(map(int, input().split()))
value = int(input())

root = None
for node in nodes:
    root = insert(root, node)

print(findSubtreeSize(root, value))
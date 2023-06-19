class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(node, data):
    if node is None:
        return Node(data)
    else:
        if data < node.data:
            node.left = insert(node.left, data)
        else:
            node.right = insert(node.right, data)
    return node

def diameter(root):
    if root is None:
        return 0, 0

    l_height, l_diameter = diameter(root.left)
    r_height, r_diameter = diameter(root.right)

    current_height = max(l_height, r_height) + 1
    current_diameter = max(l_height + r_height + 1, l_diameter, r_diameter)

    return current_height, current_diameter

N = int(input().strip())
values = list(map(int, input().strip().split()))

root = None
for val in values:
    root = insert(root, val)

_, max_diameter = diameter(root)
print(max_diameter)
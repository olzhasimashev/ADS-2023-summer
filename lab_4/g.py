class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None
    
    def insert(self, value):
        if self.root is None:
            self.root = TreeNode(value)
        else:
            self._insert_recursive(self.root, value)

    def _insert_recursive(self, current_node, value):
        if value < current_node.value:
            if current_node.left is None:
                current_node.left = TreeNode(value)
            else:
                self._insert_recursive(current_node.left, value)
        else:
            if current_node.right is None:
                current_node.right = TreeNode(value)
            else:
                self._insert_recursive(current_node.right, value)


tree = Tree()
n = input()
valuesToInsert = [int(i) for i in input().split()]

for i in valuesToInsert:
    tree.insert(i)

def findDiameter(root):
    if not root:
        return (0, 0)
    
    left = findDiameter(root.left)
    right = findDiameter(root.right)
    
    currentDiameter = left[0] + right[0]
    maxDiameter = max(left[1], right[1], currentDiameter)
    
    return (max(left[0], right[0]) + 1, maxDiameter)

print(findDiameter(tree.root)[1] + 1)
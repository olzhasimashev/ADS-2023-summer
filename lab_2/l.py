class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def findMaxSum(n: int, head: ListNode) -> int:
    if not head:
        return 0

    current_max = global_max = head.val
    node = head.next

    while node:
        current_max = max(node.val, current_max + node.val)
        global_max = max(global_max, current_max)
        node = node.next
    
    return global_max


n = int(input())
a = list(map(int, input().split()))
head = ListNode(0)
tail = ListNode(0)

for i in range(n):
	tmp = ListNode(a[i])
	if i == 0:
		head = tmp
		tail = tmp
	else:
		tail.next = tmp
		tail = tmp

print(findMaxSum(n, head))
from collections import deque

def arrange_cards(n):
    deck = deque([n])
    for i in range(n - 1, 0, -1):
        deck.appendleft(i)
        deck.rotate(i)
    return list(deck)

t = int(input())
for _ in range(t):
    n = int(input())
    result = arrange_cards(n)
    print(*result)
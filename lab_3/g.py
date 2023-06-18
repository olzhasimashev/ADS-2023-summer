n, f = map(int, input().split())
children = list(map(int, input().split()))

children.sort()

l = max(children) // f if max(children) % f == 0 else max(children) // f + 1
r = sum(children)

while l < r:
    m = (l + r) // 2
    flights = sum((ci + m - 1) // m for ci in children)
    if flights > f:
        l = m + 1
    else:
        r = m
print(l)
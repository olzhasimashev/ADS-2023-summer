n, q = map(int, input().split())
array = list(map(int, input().split()))
for _ in range(q):
    l1, r1, l2, r2 = map(int, input().split())
    count = 0
    for i in range(n):
        if l1 <= array[i] <= r1 or l2 <= array[i] <= r2:
            count += 1
    print(count)
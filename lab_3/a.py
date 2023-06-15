t = int(input())
nums = list(map(int, input().split()))
n, m = map(int, input().split())

pos = {}
for i in range(n):
    row = list(map(int, input().split()))
    if i % 2 != 0:
        row.reverse()
    for j in range(m):
        pos[row[j]] = (i, j if i%2 == 0 else m-j-1)

for num in nums:
    if num in pos:
        print(*pos[num])
    else:
        print(-1)
import sys
from bisect import bisect_left

def binary_search(mistake, blocks_cumulative):
    return bisect_left(blocks_cumulative, mistake)

n, m = map(int, sys.stdin.readline().split())
blocks = list(map(int, sys.stdin.readline().split()))
blocks_cumulative = [0]*n
blocks_cumulative[0] = blocks[0]
for i in range(1, n):
    blocks_cumulative[i] = blocks_cumulative[i-1] + blocks[i]

for _ in range(m):
    mistake = int(sys.stdin.readline())
    block = binary_search(mistake, blocks_cumulative)
    print(block + 1)
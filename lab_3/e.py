def count_pastures(length, pastures):
    count = 0
    for pasture in pastures:
        if max(pasture[0], pasture[1]) <= length:
            count += 1
    return count

def min_paddock_length(n, k, pastures):
    left = 0
    right = 10**9 + 1
    while right - left > 1:
        mid = (left + right) // 2
        if count_pastures(mid, pastures) >= k:
            right = mid
        else:
            left = mid
    return right

n, k = map(int, input().split())
pastures = []
for _ in range(n):
    xi1, yi1, xi2, yi2 = map(int, input().split())
    pastures.append((max(xi2, yi2), min(xi1, yi1)))
pastures.sort(reverse=True)
print(min_paddock_length(n, k, pastures))
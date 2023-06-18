def check(mid, n, k, pre, arr):
    j = [0]*(n+1)
    for i in range(1, n+1):
        j[i] = j[i-1]
        if pre[i] - j[i] > mid:
            if k == 0:
                return False
            j[i] += arr[i-1]
            k -= 1
    return True

def find_min_max(n, k, arr):
    arr.sort(reverse=True)
    pre = [0]*(n+1)
    for i in range(1, n+1):
        pre[i] = pre[i-1] + arr[i-1]
    left, right = 0, pre[n]
    while right - left > 1:
        mid = (right + left) // 2
        if check(mid, n, k, pre, arr):
            right = mid
        else:
            left = mid
    return right

n, k = map(int, input().split())
arr = list(map(int, input().split()))
print(find_min_max(n, k, arr))
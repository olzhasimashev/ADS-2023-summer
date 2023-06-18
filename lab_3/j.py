def can_steal(bags, hours, K):
    total_hours = sum((bag + K - 1) // K for bag in bags)
    return total_hours <= hours

def find_minimum_K(bags, hours):
    left, right = 1, max(bags)
    while left < right:
        mid = (left + right) // 2
        if can_steal(bags, hours, mid):
            right = mid
        else:
            left = mid + 1
    return left

N, H = map(int, input().split())
bags = list(map(int, input().split()))
print(find_minimum_K(bags, H))
def binary_search(arr, low, high, x):
 
    if high >= low:
 
        mid = (high + low) // 2
 
        if arr[mid] == x:
            return True
 
        elif arr[mid] > x:
            return binary_search(arr, low, mid - 1, x)
 
        else:
            return binary_search(arr, mid + 1, high, x)
 
    else:
        return False
 
n = int(input())
arr = list(map(int, input().split()))
x = int(input())
 
result = binary_search(arr, 0, len(arr)-1, x)
 
if result:
    print("Yes")
else:
    print("No")
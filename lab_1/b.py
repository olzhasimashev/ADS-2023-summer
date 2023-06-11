def younger_person(n, ages):
    stack = []
    result = []
    for i in range(n):
        while stack and stack[-1] >= ages[i]:
            stack.pop()
        if not stack:
            result.append(-1)
        else:
            result.append(stack[-1])
        stack.append(ages[i])
    return result

n = int(input().strip())
ages = list(map(int, input().strip().split()))
result = younger_person(n, ages)
print(' '.join(map(str, result)))
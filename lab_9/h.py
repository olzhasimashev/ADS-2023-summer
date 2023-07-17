s = input().strip()

n = len(s)

# Initialize count array
count = [0] * (n + 1)

# Compute the count array
for i in range(2, n + 1):
    j = i
    while j <= n:
        if s[j-1] == s[j-i]:
            count[i] += 1
        else:
            break
        j += 1

# Compute the prefix sum of count array
prefix_sum = [0] * (n + 1)
for i in range(1, n + 1):
    prefix_sum[i] = prefix_sum[i-1] + count[i]

# Calculate the number of ways
result = 0
for i in range(1, n + 1):
    if 3 * i <= n:
        result += prefix_sum[i-1]  # exclude the repetition at current index
print(result)
from collections import Counter

def find_modes(numbers):
    counts = Counter(numbers)
    max_count = max(counts.values())
    modes = [num for num, count in counts.items() if count == max_count]
    modes.sort(reverse=True)
    return modes

n = int(input())
numbers = list(map(int, input().split()))

modes = find_modes(numbers)
print(' '.join(map(str, modes)))

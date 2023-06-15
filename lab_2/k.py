t = int(input())

for _ in range(t):
    n = int(input())
    stream = input().split()
    
    frequency = {}
    first_non_repeating = []
    output = []
    
    for char in stream:
        frequency[char] = frequency.get(char, 0) + 1
        
        if frequency[char] == 1:
            first_non_repeating.append(char)
        
        while first_non_repeating:
            if frequency[first_non_repeating[0]] == 1:
                output.append(first_non_repeating[0])
                break
            else:
                first_non_repeating.pop(0)
        else:
            output.append(-1)
    
    print(' '.join(str(x) for x in output))
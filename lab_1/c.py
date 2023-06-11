def format(s):
    stack = []
    for char in s:
        if char != '#':
            stack.append(char)
        elif stack:
            stack.pop()
    return ''.join(stack)

s1, s2 = input().split()
formatted_s1 = format(s1)
formatted_s2 = format(s2)

if formatted_s1 == formatted_s2:
    print('Yes')
else:
    print('No')

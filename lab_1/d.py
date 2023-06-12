def is_balanced(s):
    if len(s) % 2 == 1:
        return False
    while len(s) > 0:
        first = s[0]
        last = s.rfind(first)
        if last == -1 or last % 2 == 0:
            return False
        else:
            s = s[1:last]
    return True

s = input().strip()
print("YES" if is_balanced(s) else "NO")
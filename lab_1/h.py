def is_prime(n):
    factor = 2
    if n == 1:
        return False
    
    while (factor * factor <= n):
        if n % factor == 0:
             return False
        factor +=1
    return True


n = int(input())

result = is_prime(n)

if result:
    print('YES')
else:
    print('NO')
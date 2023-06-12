from collections import deque

def nth_prime_number(n):
    prime_numbers = deque()

    if n==1:
        return 3
    count = 1
    pr_num = 1
    while(count < n*n):
        pr_num +=2
        if is_prime(pr_num):
            count +=1
        if is_prime(pr_num) and is_prime(count):
            prime_numbers.append(pr_num)

    print(prime_numbers)

    return prime_numbers[n-1]



def is_prime(pr_num):
    factor = 2
    while (factor * factor <= pr_num):
        if pr_num % factor == 0:
             return False
        factor +=1
    return True


n = int(input())

result = nth_prime_number(n)

print(result)
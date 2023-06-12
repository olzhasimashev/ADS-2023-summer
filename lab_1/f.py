def nth_prime_number(n):
    if n==1:
        return 2
    count = 1
    pr_num = 1
    while(count < n):
        pr_num +=2
        if is_prime(pr_num):
            count +=1
    return pr_num

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
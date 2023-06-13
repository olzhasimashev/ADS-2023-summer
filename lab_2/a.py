from collections import deque

def nearest_number(n, values):
    difference = abs(n - values[0])
    answer = 0
    for i in values:
        
        if abs(n - i) < difference:
            difference = abs(n - i)
            answer = values.index(i)
    print(answer)


size = int(input())

values = list(map(int, input().split()))

number = int(input())

result = nearest_number(number, values)
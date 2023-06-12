from collections import deque

def process_deque(input):
    if input == '':
        pass
    
    if input[0] == '+':
        result.append(int(input[1]))

    if input[0] == '-':
        result.appendleft(int(input[1]))

    if input[0] == '*' and len(result) > 1:
        print(result[0] + result[-1])
        result.pop()
        result.popleft()
    elif input[0] == '*' and len(result) == 0:
        print('error')
    elif input[0] == '*' and len(result) == 1:
        print(result[0] + result[-1])
        result.pop()

    if input[0] == '!':
        return '!'

character = lambda a : a

result = deque()

while character != '!':
    
    expression = input().split()
    if len(expression) != 0:
        character = process_deque(expression)
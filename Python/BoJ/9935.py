string = input()
explosion = input()
boom = explosion[-1]
length = len(explosion)
stack = []

for char in string:
    stack.append(char)
    if char == boom and ''.join(stack[-length:]) == explosion:
        del stack[-length:]

answer = ''.join(stack)

if len(answer) == 0:
    print('FRULA')
else:
    print(answer)


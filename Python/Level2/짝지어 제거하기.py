# stack을 활용해 짝지어 제거

def solution(s):
    answer = 0
    result = ""
    
    stack = []
    
    for x in s:
        if len(stack) == 0:
            stack.append(x)
        else:
            if stack[-1] == x:
                stack.pop()
            else:
                stack.append(x)
    
    if len(stack) == 0:
        return 1
    else:
        return 0
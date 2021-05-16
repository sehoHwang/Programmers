import functools

def compare(a, b):
    if a+b > b+a:
        return 1
    elif a+b == b+a:
        return 0
    else:
        return -1

def solution(numbers):
    answer = ''
    
    num = list(map(str,numbers))
    num.sort(key = functools.cmp_to_key(compare), reverse=True)
    #print(num)
    return str(int(answer.join(num)))
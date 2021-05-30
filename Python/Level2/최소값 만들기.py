from itertools import product

def solution(A,B):
    answer = 0
    A = sorted(A)
    B = sorted(B, reverse=True)

    result = []
    for a, b in zip(A,B):
        result.append(a*b)
    print(result)
    return sum(result)
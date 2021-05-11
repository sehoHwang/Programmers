"""
    <Solution>

    1. permutations를 사용해서 1부터 numbers의 길이만큼의 순열을 구함

    2. 각 길이에서의 결과를 join을 사용해 빈 문자열에 합치고 int로 변형 후 num_case 리스트에 추가 -> 중복제거(set 활용)

    3. 제곱근 + 1 값까지만 비교하면 소수 판별 가능
"""

from itertools import permutations
import math

def isPrime(n):
    if n==0 or n==1:
        return False
    if n==2 or n==3:
        return True
    for i in range(2, int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True

def solution(numbers):
    answer = 0
    num = []
    num_case = []
    for x in numbers:
        num.append(str(x))
        
    for i in range(1, len(num)+1):
        tmp = list(permutations(num, i))
        for j in tmp:
            tmp_str = "".join(j)
            num_case.append(int(tmp_str))
    
    num_case = list(set(num_case))

    for x in num_case:
        if isPrime(x):
            answer+=1
            
    return answer
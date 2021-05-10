# isalpha() 를 통해 영문인지 확인

# 원소의 중복 허용을 위해 

# 교집합 = 길이가 작은 집합에 포함되는 문자를 순회하며 (for x in str1 if x in str2) inter 리스트에 삽입
# 이 때, 크기가 큰 리스트는 해당 x를 remove()를 통해 제거

# 합집합 = remove가 시행된 str2 + str1

# 이렇게 접근하면 다중집합에 대해 확장할 수 있다.

import math

def solution(str1, str2):
    answer = 0
    set1 = []
    set2 = []
    for i in range(len(str1)-1):
        if str1[i].isalpha() and str1[i+1].isalpha():
            set1.append(str1[i:i+2].lower())
    
    for i in range(len(str2)-1):
        if str2[i].isalpha() and str2[i+1].isalpha():
            set2.append(str2[i:i+2].lower())
        
    #print(set1)
    #print(set2)
    
    if len(set1) > len(set2):
        inter = [set1.remove(x) for x in set2 if x in set1]
    else:
        inter = [set2.remove(x) for x in set1 if x in set2]
    
    list_uni = set1 + set2
    uni = len(list_uni)
    
    if uni == 0:
        return 65536
    
    return int(len(inter)/uni * 65536)
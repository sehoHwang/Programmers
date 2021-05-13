"""
    Solution

    1. '{' 와 '}'를 먼저 제거한다.

    2. ','를 기준으로 list에 저장한다.

    3. dictionary를 사용해 각 숫자를 key로 등장 횟수를 value로 저장한다.

    4. dict_tuple 형태로 (dict.items()) 변환해 내림차순 정렬을 하고 result에 담는다.

    5. result를 순회하며 answer.append()
"""

def solution(s):
    answer = []
    set = {}
    s = s.replace('{','').replace('}', '')
    idx = 0
    for i in range(len(s)):
        if s[i]==',':
            tmp = s[idx:i]
            if tmp in set:
                set[tmp]+=1
            else:
                set[tmp]=1
            idx = i+1
    tmp = s[idx:len(s)]
    if tmp in set:
        set[tmp]+=1
    else:
        set[tmp] = 1
    
    result = sorted(set.items(), key = lambda x:x[1], reverse= True)
    for x in result:
        answer.append(int(x[0]))
    
    return answer



"""
    New solution

    1. 리스트의 not in 과 list.sort(key = len)을 사용한 솔루션
"""

def solution(s):
    answer = []
    new_s = []
    s = s[2:-2]
    
    new_s = s.split('},{')
    new_s.sort(key = len)
    
    for x in new_s:
        tmp = x.split(',')
        for i in tmp:
            if int(i) not in answer:
                answer.append(int(i))
    
    return answer
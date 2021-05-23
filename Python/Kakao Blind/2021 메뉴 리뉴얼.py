"""
    Solution

    1. orders의 각 원소를 오름차순으로 정렬한다. sorted() 함수 사용

    2. course에 있는 개수 별로 조합을 구해 dictionary 자료구조에 삽입한다 (key : 메뉴, value : 나타난 갯수)

    3. dictionary를 순회하며 각 갯수별로 최댓값을 구한 후 최댓값이 2 이상일 경우 최댓값에 해당하는 key 값을 answer에 삽입한다.
"""

from itertools import combinations

def solution(orders, course):
    answer = []
    dic = {}
    new_orders = []
    for x in orders:
        new_orders.append(sorted(x))
    
    
    for x in course:
        for i in new_orders:
            tmp = list(combinations(i, x))
            for j in tmp:
                string="".join(j)
                if string in dic:
                    dic[string] += 1
                else:
                    dic[string] = 1
        
    for x in course:
        max_val = 0
        for d in dic:
            if len(d) == x:
                if max_val < dic[d]:
                    max_val = dic[d]

        for i in dic:
            if max_val>=2 and dic[i] == max_val and len(i) == x:
                answer.append(i)
    answer.sort()     
    return answer
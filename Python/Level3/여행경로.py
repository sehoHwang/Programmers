from collections import defaultdict

def solution(tickets):
    answer = []
    stack = []
    route = defaultdict(list)  # defaultdict를 사용해서 기본 value 타입을 list로 설정
    
    for t in tickets:
        route[t[0]].append(t[1])  # defaultdict를 사용함으로써, 키의 유무를 판단하지 않아도 된다.
    
    for v in route.values():
        v.sort()
        
    reverse_path = []  # 추후에 역순으로 정렬하기위한 list
    stack.append("ICN")
    while len(stack)>0:
        top = stack[-1]  # top 반환없이 가져오기
        if len(route[top])>0 :
            stack.append(route[top][0])
            del route[top][0]
        else:
            stack.pop()
            reverse_path.append(top)
    reverse_path.reverse()
    return reverse_path
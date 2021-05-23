from itertools import combinations

def solution(relation):
    n_row = len(relation)
    n_col = len(relation[0])
    combi = []
    result = []
    for i in range(1, n_col+1):
        combi.extend(combinations(range(n_col), i)) # append는 해당 값을 추가 , extend는 각 iter를 추가
    
    for keys in combi:
        tmp = [tuple(item[key] for key in keys) for item in relation]
        if len(set(tmp)) == n_row:
            result.append(keys)

    answer = set(result)
    
    for i in range(len(result)):
        for j in range(i+1,len(result)):
            if len(result[i])==len(set(result[i]).intersection(set(result[j]))): # 이전 집합과 다음 집합의 교집합의 길이가 이전 집합과 동일하면 answer에서 삭제
                answer.discard(result[j]) # remove() vs discard() -> remove()는 해당 key가 없으면 에러. but, discard()는 정상 작동 -> discard()는 key의 존재 유무 판별에도 사용 가능.
    
    return len(answer)
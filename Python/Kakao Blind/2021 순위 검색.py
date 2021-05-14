from itertools import combinations

def solution(info, query):
    answer = []
    db = {}
    
    for i in info:
        tmp = i.split() # info를 공백 기준으로 split
        conditions = tmp[:-1] # score를 제외한 부분
        score = int(tmp[-1]) # score 부분
        for n in range(5):
            combi = list(combinations(range(4), n)) # '-'가 들어갈 수 있는 조합
            for c in combi:
                t_c = conditions.copy()
                for v in c: # 각 조합의 인덱스 v에 '-'를 삽입
                    t_c[v] = '-'
                changed_t_c = '/'.join(t_c) 
                if changed_t_c in db: # 이미 dict에 있을 경우 socre를 list처럼 추가
                    db[changed_t_c].append(score)
                else:
                    db[changed_t_c] = [score] # dict에 없을 경우 score를 list형으로 삽입
    for value in db.values():
        value.sort() # 추후에 이분 탐색을 위해 value 부분을 정렬

    
    for q in query:
        qry = [i for i in q.split() if i!= 'and']
        qry_cnd = '/'.join(qry[:-1])
        qry_score = int(qry[-1])
        if qry_cnd in db:
            if len(db[qry_cnd]) > 0:
                s, e = 0, len(db[qry_cnd])
                while s!=e and s!=len(db[qry_cnd]):
                    mid = (s+e)//2
                    if db[qry_cnd][mid] < qry_score:
                        s = mid + 1
                    else:
                        e = mid
                answer.append(len(db[qry_cnd])-s)
        else:
            answer.append(0)
    
    return answer
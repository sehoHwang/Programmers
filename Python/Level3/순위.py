# 플로이드 와샬

def solution(n, results):
    answer = 0
    
    result = [[0 for i in range(n)] for j in range(n)]
    
    for r in results:
        s, e = r[0], r[1]
        result[s-1][e-1] = 1

    for i in range(n):
        for j in range(n):
            for z in range(n):
                if result[j][i] and result[i][z]:
                    result[j][z] = 1
                    
    for i in range(n):
        tmp1, tmp2 = 0, 0
        for j in range(n):
            tmp1+=result[i][j]
        for z in range(n):
            tmp2 += result[z][i]
        if tmp1+tmp2 == n-1:
            answer+=1
            
    return answer

# 해시(딕셔너리)

def solution(n, results):
    answer = 0
    win = {}
    lose = {}
    
    for i in range(1, n+1):
        win[i] = set()
        lose[i] = set()
    
    for r in results:
        w, l = r[0], r[1]
        if w not in win:
            win[w] = {l}
        else:
            win[w].add(l)
        if l not in lose:
            lose[l] = {w}
        else:
            lose[l].add(w)
    
    for i in range(1, n+1):
        for j in win[i]:
            lose[j] |= lose[i] # i에게 패배한 j, j를 이긴 집단에 i를 이긴 집단을 합집합
        for z in lose[i]:
            win[z] |= win[i] # i에게 승리한 z, z에게 패배한 집단에 i가 승리한 집단을 합집합
    
    for i in range(1, n+1):
        if len(win[i]) + len(lose[i]) == n-1:
            answer+=1
    
    return answer
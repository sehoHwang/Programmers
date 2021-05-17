# dp

def solution(m, n, puddles):
    answer = 0
    
    road = [[0 for i in range(m)] for j in range(n)] 
    road[0][0] = 1
    for i in range(n):
        for j in range(m):
            if [j+1, i+1] in puddles:
                continue
            if i == 0 and j == 0:
                continue
            road[i][j] = road[i-1][j] + road[i][j-1]
    
    return road[-1][-1]%1000000007
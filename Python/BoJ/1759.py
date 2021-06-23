def dfs(len, idx):
    if len == L:
        count = count_vowels(arr)
        if count>=1 and L-count>=2:
            print(''.join(arr))
            return
    
    for i in range(idx, C):
        if visit[i] == 0:
            visit[i] = 1
            arr.append(alpha[i])
            dfs(len+1, i+1)
            visit[i] = 0
            del arr[-1]

def count_vowels(string_a):
    cnt=0
    for a in string_a:
        if a in 'aeiou':
            cnt+=1
    return cnt

L, C = map(int, input().split())

alpha = list(input().split())
arr = []
visit = [0 for _ in range(C)]
alpha.sort()
dfs(0, 0)
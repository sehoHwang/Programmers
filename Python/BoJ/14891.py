def rotate(tmp, d, status):
    if d == 1: # 원래 방향이 시계방향 이었을 경우
        if status == True:
            last = st[tmp][7] 
            for idx in range(7,0, -1):
                st[tmp][idx] = st[tmp][idx-1]
            st[tmp][0] = last
        else:
            first = st[tmp][0]
            for idx in range(0,7):
                st[tmp][idx] = st[tmp][idx+1]
            st[tmp][7] = first
    else:
        if status == False:
            last = st[tmp][7] 
            for idx in range(7,0, -1):
                st[tmp][idx] = st[tmp][idx-1]
            st[tmp][0] = last
        else:
            first = st[tmp][0]
            for idx in range(0,7):
                st[tmp][idx] = st[tmp][idx+1]
            st[tmp][7] = first

def strTolist(str):
    tmp = []
    for s in str:
        tmp.append(s)
    return tmp

st = []
for _ in range(4):
    st.append(strTolist(input()))
#print(st)

K = int(input())

for _ in range(K):
    num, dir = map(int, input().split())
    condition = [[] for _ in range(4)]
    status_r = True
    status_l = True
    condition[num-1] = [dir, True]
    if num!=4:
        for i in range(num, 4): # 오른쪽으로
            if st[i-1][2] == st[i][6]:
                break
            status_r = not status_r
            condition[i] = [1, status_r]

    if num!=1:
        for j in range(num-1, 0, -1): # 왼쪽 방향
            if st[j][6] == st[j-1][2]:
                break
            status_l = not status_l
            condition[j-1] = [1, status_l]
    
    for i in range(4):
        if len(condition[i])>1:
            rotate(i, dir, condition[i][1])
    
result = 0
if st[0][0] == '1':
    result +=1
if st[1][0] == '1':
    result+=2
if st[2][0] == '1':
    result+=4
if st[3][0] == '1':
    result+=8
print(result)
    
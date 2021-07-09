def move_down(arr, cur):
    idx = cur+1
    while idx<len(arr) and arr[idx]!=1:
        idx+=1
    
    if idx==len(arr): # 삭제 행이 마지막이었을 경우
        idx = move_up(arr,cur)
    
    return idx
    
def move_up(arr, cur):
    idx = cur-1
    while arr[idx]!=1:
        idx-=1
    return idx

def selectU(arr, selected, offset):
    idx = selected-1
    count = int(offset)
    while True:
        if arr[idx] == 1:
            count-=1
        if count == 0:
            break
        idx-=1
    return idx

def selectD(arr, selected, offset):
    idx = selected+1
    count = int(offset)
    while True:
        if arr[idx] == 1:
            count-=1
        if count == 0:
            break
        idx+=1
    return idx
    
def solution(n, k, cmd):
    answer = ''
    arr = [1 for _ in range(n)]
    stack = []
    selected = k
    
    for c in cmd:
        if len(c) == 1:
            if c == 'C':
                arr[selected] = 0
                stack.append(selected)
                selected = move_down(arr, selected)
            elif c == 'Z':
                restore = stack.pop()
                arr[restore] = 1
                
        else:
            inst, offset = c.split()
            if inst == 'U':
                selected = selectU(arr, selected, offset)
                
            elif inst == 'D':
                selected = selectD(arr, selected, offset)
    #print(arr)
    for a in arr:
        if a == 1:
            answer+='O'
        else:
            answer+='X'
    return answer


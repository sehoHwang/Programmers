T = int(input())
for _ in range(T):
    function = input() # 함수
    function.replace('RR', '')
    n = int(input()) # 배열의 개수
    arr_input = input()
    arr_input = arr_input.replace(']','').replace('[','')
    l, r, d = 0, 0, True
    if function.count('D') > len(arr_input):
        print('error')
        continue
    l, r= 0,0
    if len(arr_input) != 0:
        arr = list(arr_input.split(','))
    else:
        if 'D' in function:
            print('error')
        else:
            print('[]')
        continue
    for p in function:
        
        if p == 'R':
            d = not d
        else:
            if d: l+=1
            else: r+=1

    if l+r <= n:
        res = arr[l:n-r]
        if d: print('['+','.join(res)+']')
        else: print('['+','.join(res[::-1])+']')
    else:
        print('error')
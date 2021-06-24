T = int(input())
for _ in range(T):
    function = input() # 함수
    function.replace('RR', '')
    n = int(input()) # 배열의 개수
    arr_input = input()
    arr_input = arr_input.replace(']','').replace('[','')

    if function.count('D') > len(arr_input):
        print('error')
        continue
    l, r= 0,0
    if len(arr_input) != 0:
        arr = list(map(int,arr_input.split(',')))
    else:
        if 'D' in function:
            print('error')
        else:
            print('[]')
        continue
    for p in function:
        if p == 'R':
            arr.reverse()
        else:
            if len(arr) == 0:
                print('error')
                break
            del arr[0]
    if len(arr) != 0:
        print(arr)
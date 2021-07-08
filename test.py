from queue import PriorityQueue

def find_minValue(s, e):
    temp = max(arr)
    idx = 0
    for i in range(s,e+1):
        temp = min(temp, arr[i])
        if temp == arr[i]:
            idx = i
    return temp, idx

arr = [5,2, 3, 1, 6]

for i in range(len(arr)-1):
    minValue, index = find_minValue(i+1, len(arr)-1)
    if arr[i] < minValue:
        tmp = arr[i]
        arr[i] = find_minValue(i+1, len(arr))
        arr[index] = tmp

print(arr)
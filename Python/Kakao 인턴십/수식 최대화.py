# permutations 사용

# python은 for문일 시 만약 list의 길이를 구간의 최댓값으로 설정할 시 자동으로 줄어들지 않으므로
# 이럴 경우에는 while문을 사용할 것

from itertools import permutations

def solution(expression):
    answer = 0
    result = []
    numbers = []
    op = []
    arr = ['*', '+', '-']
    exp = list(permutations(arr, 3))

    idx = 0
    
    for i in range(len(expression)):
        if expression[i] in arr:
            numbers.append(expression[idx:i])
            op.append(expression[i])
            idx = i+1
            
    numbers.append(expression[idx:len(expression)])
    tmp_op = op[:]
    
    for x in exp:
        tmp_num = numbers[:]
        tmp_op = op[:]
        for i in range(0,len(x)):
            j = 0
            while len(tmp_op)!=0 and j<len(tmp_op):
                if x[i] == tmp_op[j]:
                    tmp_num[j] = str(eval(tmp_num[j]+tmp_op[j]+tmp_num[j+1]))
                    del tmp_num[j+1]
                    del tmp_op[j]
                else:
                    j+=1
        result.append(abs(int(tmp_num[0])))
    
    answer = max(result)        
    
    return answer


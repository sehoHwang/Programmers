def transform(matrix, q, maxVal):
    y1, x1, y2, x2 = q[0]-1, q[1]-1, q[2]-1, q[3]-1
    
    tmp_matrix = [[i for i in matrix[j]] for j in range(len(matrix))]    # 그냥 copy를 하면 기존 값도 수정되기 때문에 이렇게 할당해야함 
    
    minVal = maxVal
    for i in range(x1, x2+1):
        if i==x1:
            tmp_matrix[y1][i] = matrix[y1+1][i]
            minVal = min(minVal, tmp_matrix[y1][i])
        else:
            tmp_matrix[y1][i] = matrix[y1][i-1]
            minVal = min(minVal, tmp_matrix[y1][i])
    
    for j in range(x1, x2+1):
        if j==x2:
            tmp_matrix[y2][j] = matrix[y2-1][j]
            minVal = min(minVal, tmp_matrix[y2][j])
        else:
            tmp_matrix[y2][j] = matrix[y2][j+1]
            minVal = min(minVal, tmp_matrix[y2][j])
    
    if y1+1<=y2-1:
        for i in range(y1+1, y2):
            tmp_matrix[i][x1] = matrix[i+1][x1]
            minVal = min(minVal, tmp_matrix[i][x1])
            tmp_matrix[i][x2] = matrix[i-1][x2]
            minVal = min(minVal, tmp_matrix[i][x2])
            
    return tmp_matrix, minVal
    
def solution(rows, columns, queries):
    answer = []
    
    matrix = [[columns*j+(i+1) for i in range(columns)] for j in range(rows)]
    maxVal = max(matrix[len(matrix)-1])
    
    for q in queries:
        nxt_matrix, minVal = transform(matrix, q, maxVal)
        matrix = nxt_matrix
        answer.append(minVal)
        
    return answer
"""
    Solution

    1. 삭제되는 result의 값이 있는 동안 반복

    2. 삭제될 수 있는 부분을 이중 for문을 통해 탐색 후 삭제되는 범위 모두 visit[][] = True로 설정

    3. visit을 순회하여 True인 경우 빈칸으로 삽입

    4. 빈 칸일시 연산을 위해 전치 리스트를 rotate_board에 삽입

    5. 빈 칸을 처리 후 다시 전치를 시켜 tmp_board에 삽입 후 삭제된 횟수(cnt)와 tmp_board를 반환

    6. 1~5를 반복
 
"""


def visitBlock(m, n, board, visit):
    for i in range(1, m):
        for j in range(1, n):
            if board[i][j] != ' ' and board[i][j] == board[i][j-1] and board[i][j-1:j+1] == board[i-1][j-1:j+1]:
                print(i, j)
                print(i, j-1)
                print(i-1, j)
                print(i-1, j-1)
                visit[i][j] = True
                visit[i][j-1] = True
                visit[i-1][j] = True
                visit[i-1][j-1] = True
    #print(visit)
    
def delBlock(m, n, board, visit):
    rotate_board = []
    tmp_board = []
    cnt = 0
    for i in range(m):
        for j in range(n):
            if visit[i][j] == True:
                cnt+=1
                board[i] = board[i][:j]+ ' ' + board[i][j+1:]
                
    for i in range(n):
        tmp = ''
        for j in range(m):
            tmp += board[j][i]
        rotate_board.append(tmp)
    #print(rotate_board)
    
    for i in range(n):
        for j in range(m):
            if rotate_board[i][j] == ' ':
                rotate_board[i] = ' '+rotate_board[i][:j] + rotate_board[i][j+1:]
    #print(rotate_board)
    
    for i in range(m):
        tmp = ''
        for j in range(n):
            tmp += rotate_board[j][i]
        tmp_board.append(tmp)
    #print(tmp_board)
    return cnt, tmp_board
    
def solution(m, n, board):
    answer = 0
    result = 1
    
    while result:
        visit = [[False]*n for _ in range(m)] 
        visitBlock(m, n, board, visit)
        result, board = delBlock(m, n, board, visit)
        answer += result
        
    return answer
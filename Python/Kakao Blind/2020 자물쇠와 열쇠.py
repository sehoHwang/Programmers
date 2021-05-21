def rotate_90(key):
    return list(zip(*key[::-1]))

def attach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] += key[i][j]

def detach(x, y, M, key, board):
    for i in range(M):
        for j in range(M):
            board[x+i][y+j] -= key[i][j]

def check(board, M, N):
    for i in range(N):
        for j in range(N):
            if board[M+i][M+j] != 1:
                return False
    return True
            
def solution(key, lock):
    answer = False
    
    M, N = len(key), len(lock)
    
    block = [[0]*(M*2+N) for _ in range(M*2+N)]
    
    for i in range(N):
        for j in range(N):
            block[i+M][j+M] = lock[i][j]
            
    rotate_key = key
    
    for _ in range(4):
        rotate_key = rotate_90(rotate_key)
        for x in range(1, M+N):
            for y in range(1, M+N):
                attach(x, y, M, rotate_key, block)
                if check(block, M, N):
                    return True
                detach(x, y, M, rotate_key, block)
    
    return answer
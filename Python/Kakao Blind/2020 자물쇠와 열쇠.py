def rotate_90(new_key):
    N = len(new_key)
    new = [[0]*N for _ in range(N)]
    pos = []
    for i in range(N):
        for j in range(N):
            if new_key[i][j] == 1:
                pos.append((i, j))
    for y, x in pos:
        new_x = N-1-y
        new_y = x
        new[new_y][new_x] = 1
    return new

def extension(lock, N):
    new_lock = [[0]*3*N for _ in range(3*N)]
    for i in range(N, 2*N):
        for j in range(N, 2*N):
            new_lock[i][j] = lock[i-N][j-N]
    return new_lock
    #print(new_lock)
    
def move(key, lock, N):
    key_set = set()
    lock_hole = set()
    lock_field = set()
    for i in range(len(key)):
        for j in range(len(key)):
            if key[i][j] == 1:
                key_set.add((i,j))
    for i in range(N, 2*N):
        for j in range(N, 2*N):
            if lock[i][j] == 0:
                lock_hole.add((i,j))
    
    if len(lock_hole.intersection(key_set)) == len(key_set):
        return True
    else:
        right_key = [[0]*len(key) for _ in range(len(key))]
        down_key = [[0]*len(key) for _ in range(len(key))]
        for i in range(len(key)):
            for j in range(len(key)):
                if key[i][j] == 1:
                    right_key
                

def solution(key, lock):
    answer = True
    N = len(lock)
    ex_lock = extension(lock, N)
    
    move(rotate_90(key), ex_lock, N)
    
    
    return answer
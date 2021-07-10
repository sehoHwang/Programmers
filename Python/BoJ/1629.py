def dnc(length):
    if length == 1:
        return A%C
    if length%2==0:
        left = dnc(length//2)
        return left*left%C
    else:
        left = dnc(length//2)
        return left*left*A%C
        
A, B, C = map(int, input().split())
print(dnc(B))


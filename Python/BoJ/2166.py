n = int(input())

dots_x = []
dots_y = []

for _ in range(n):
    A, B = map(int, input().split())
    dots_x.append(A)
    dots_y.append(B)

total_x, total_y = 0, 0

for i in range(n):
    if i == n-1:
        total_x += dots_x[i]*dots_y[0]
        total_y += dots_y[i]*dots_x[0]
    else:
        total_x += (dots_x[i]*dots_y[i+1])
        total_y += (dots_y[i]*dots_x[i+1])

print(round(abs(total_x-total_y)/2, 2))

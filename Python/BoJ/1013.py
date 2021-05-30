N = int(input())

s = set()
s.add("100")
s.add("01")

for _ in range(N):
    string = input()
    idx = 0
    tmp = ""
    last = ''
    while idx<len(string):
        tmp+=string[idx]
        if tmp not in s:
            continue
        else:
            last = tmp[len(tmp)-1]
            
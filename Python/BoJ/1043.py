N, M = map(int, input().split())

withness_num = set(map(int, input().split()[1:]))
party_list = []
possible_list = []
for _ in range(M):
    party_list.append(set(map(int, input().split()[1:])))
    possible_list.append(1)

for _ in range(M):
    for idx, party in enumerate(party_list):
        if withness_num.intersection(party):
            possible_list[idx] = 0
            withness_num = withness_num.union(party)

print(sum(possible_list))
import sys

n = int(sys.stdin.readline())

info ={}
for _ in range(n):
    idx, size = map(int, sys.stdin.readline().strip().split())
    info[idx]=size

info2 = sorted(info.items())
answer=0
max_idx=0
max_size =0
min_start = min(info2)[0]
max_start = max(info2)[0]

for i in range(len(info2)):
    if max_size < info2[i][1]:
        max_size = info2[i][1]
        max_idx = info2[i][0]
answer += max_size

temp = info.get(min_start)
for i in range(min_start, max_idx):
    if info.get(i) == None:
        answer += temp
    elif info.get(i) > temp:
        temp = info.get(i)
        answer += temp
    else:
        answer += temp
temp = info.get(max_start)
for i in range(max_start, max_idx, -1):
    if info.get(i) == None:
        answer += temp
    elif info.get(i) > temp:
        temp = info.get(i)
        answer += temp
    else:
        answer += temp
print(answer)

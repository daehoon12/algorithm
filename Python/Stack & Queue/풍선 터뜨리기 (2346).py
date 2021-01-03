import sys

n = int(sys.stdin.readline())
lst=[]
num=1
size = n
for i in list(map(int, sys.stdin.readline().strip().split())):
    lst.append([num, i])
    num+=1
size = n
answer=[]
idx=0
for _ in range(n):
    answer.append(lst[idx][0])
    move = lst[idx][1]
    lst.pop(idx)
    idx = move + idx
    size -= 1
    if size == 0:
        break
    if move > 0:
        idx-=1
        idx = idx%size
    else:
        idx = (size+ idx)%size
print(*answer)

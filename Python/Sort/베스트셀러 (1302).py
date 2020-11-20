import sys

N = int(sys.stdin.readline())
d = {}
for _ in range(N):
    name = sys.stdin.readline().strip()
    if d.get(name) != None:
        d[name] +=1
    else:
        d[name]=1
answer = sorted(d.items(), key = lambda x: (-x[1], x[0]))
print(answer[0][0])

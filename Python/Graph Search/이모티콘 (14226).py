import sys
from collections import deque

def bfs(start):
    q = deque()
    q.append([start,0])
    dist[start][0]=0
    while q:
        y,x = q.popleft()
        if dist[y][y]== -1: # 1번 연산 : 붙여넣기
            dist[y][y] = dist[y][x] +1
            q.append([y,y])
        if x+ y <= n and dist[y+x][x] == -1: # 2번 연산 : 붙여넣기
            dist[y+x][x] = dist[y][x]+1
            q.append([y+x, x])
        if y-1 >=0 and dist[y-1][x] == -1: # 3번 연산 : 삭제
            dist[y-1][x] = dist[y][x]+1
            q.append((y-1,x))

n = int(sys.stdin.readline())
dist=[[-1]*(n+1) for i in range(n+1)] # 2차원 리스트로 접근, 이게 핵심
bfs(1)
r=9876543210
for i in dist[n][1:]:
    if i != -1:
        r = min(i, r)
print(r)

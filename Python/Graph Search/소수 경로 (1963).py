import sys
from collections import deque
primeNum = [False for _ in range(10001)]

def eratos():
    for i in range(2,10000):
        if primeNum[i] == True:
            continue
        for j in range(2*i, 10000, i):
            primeNum[j] = True

def bfs(s,e):
    dq = deque()
    dq.append(s)
    visit[s] =1
    while dq:
        step = dq.popleft()
        now = str(step)
        if(step == e):
            return visit[e];
        for i in range(4):
            for j in map(str, range(10)): # j에 str mapping
                if i == 0 and j=='0':
                    continue
                num = int(now[:i] + j + now[i+1:]) # C++으로 풀었을 때 처럼 str로 접근하나 코드가 다름..
                if visit[num] == 0 and primeNum[num] == False:
                    visit[num] =visit[step] +1
                    dq.append(num)

N = int(sys.stdin.readline())
eratos()
for _ in range(N):
    visit = [0 for _ in range(10001)]
    s, e = map(int, sys.stdin.readline().split())
    print(bfs(s,e)-1)

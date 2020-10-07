import sys
from collections import deque

N, E, start = map(int, sys.stdin.readline().split())

# 인접 리스트 만들기
adj = [list([]) for _ in range(N+1)]
for _ in range(E):
    n1, n2 = map(int, sys.stdin.readline().split())
    adj[n1].append(n2)
    adj[n2].append(n1)

# 정렬
for edge in adj:
    edge.sort()
def dfs(num, visit):
    visit.append(num)
    for next_node in adj[num]:
        if next_node not in visit:
            visit = dfs(next_node, visit)

    return visit

def bfs(num):
    dq = deque()
    dq.append(num)
    visit =[]
    visit.append(num)
    while dq:
        curr_node = dq.popleft()
        for next_node in adj[curr_node]:
            if next_node not in visit:
                visit.append(next_node)
                dq.append(next_node)

    return visit

print(*dfs(start, []))
print(*bfs(start))
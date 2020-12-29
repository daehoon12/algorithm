import sys
import heapq

def dijkstra(start):
    heap =[]
    dist[start]=0
    heapq.heappush(heap, [0,start])

    while heap:
        curr_dist, curr_num = heapq.heappop(heap)
        if dist[curr_num] < curr_dist:
            continue            
        for curr in v[curr_num]:
            next_num = curr[1]
            next_dist = curr[0] + curr_dist
            
            if next_dist < dist[next_num]:
                dist[next_num]=next_dist
                heapq.heappush(heap, [next_dist, next_num])


n, e = map(int, sys.stdin.readline().split())
k = int(sys.stdin.readline())

dist= [987654321]*(n+1)
v = [[] for _ in range(n+1)]

for _ in range(e):
    start, end, weight = map(int, sys.stdin.readline().split())
    v[start].append([weight, end])
dijkstra(k)

for i in range(1, n+1):
    if dist[i] == 987654321:
        print("INF")
    else:
        print(dist[i])

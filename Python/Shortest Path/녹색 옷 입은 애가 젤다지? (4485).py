import sys
import heapq
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def djikstra(y,x):
    heapq.heappush(heap, [arr[y][x], y,x])
    dist[y][x] = arr[y][x]
    while heap:
        curr_w, curr_y, curr_x = heapq.heappop(heap)
        if dist[curr_y][curr_x] < curr_w:
            continue
        for i in range(4):
            cx = curr_x + dx[i]
            cy = curr_y + dy[i]
            if cx < 0 or cx >= n or cy<0 or cy >=n:
                continue
            next_w = curr_w + arr[cy][cx]
            if next_w < dist[cy][cx]:
                dist[cy][cx] = next_w
                heapq.heappush(heap, [next_w, cy,cx])

problem_cnt=1
while True:
    n = int(sys.stdin.readline())
    if n ==0:
        break
    arr=[]
    heap=[]
    for i in range(n):
        arr.append(list(map(int, sys.stdin.readline().split())))
    dist = [[987654321]*n for _ in range(n)]
    djikstra(0,0)
    print("Problem " + str(problem_cnt) +":", dist[n-1][n-1])
    problem_cnt+=1

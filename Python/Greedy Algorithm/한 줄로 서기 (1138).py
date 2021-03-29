import sys,heapq

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))
heap =[]
for i in range(len(arr)):
    heapq.heappush(heap, [-(i+1), arr[i]]) # 자신의 왼쪽에 몇명 있는지를 기준으로 max heap으로 삽입.

answer=[]
while heap:
    tall, idx = heapq.heappop(heap) # 큐에서 하나씩 값을 빼면서 tall을 answer에 넣는다.
    answer.insert(idx, -tall) 
print(*answer)

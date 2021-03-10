from collections import deque

def solution(prices):
    answer = []
    q = deque(prices)
    while q:
        price = q.popleft() # 맨 앞부터 탐색.
        cnt=0
        for i in q:
            cnt+=1
            if price > i: # 현재 값이 i보다 크면 탈출
                break
        answer.append(cnt)
    return answer
        

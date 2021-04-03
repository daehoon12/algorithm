import heapq

def solution(jobs):
    answer,now,i = 0,0,0
    start = -1
    heap =[]
    
    while True:
        if i >= len(jobs):
            break
        
        for j in jobs:
            if start <j[0]<=now:
                heapq.heappush(heap,[j[1],j[0]]) # 작업 소요시간 순으로 넣음
        
        if len(heap)>0:
            curr =heapq.heappop(heap) # curr[0] : 작업의 소요시간, curr[1] : 작업이 요청되는 시점
            start =now #
            now+= curr[0] 
            answer +=(now-curr[1]) # 현재 시점에서 작업이 요청되는 시간을 빼면 걸리는 시간.
            i+=1 # i는 반복문 탈출용 변수
        
        else:
            now+=1
            
    return answer//len(jobs)

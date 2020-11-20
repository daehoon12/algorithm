import sys

T = int(sys.stdin.readline())
d = {}
l =[]
for _ in range(T):
    answer=1
    n = int(sys.stdin.readline())
    for _ in range(n):
        a, b = map(str,sys.stdin.readline().split())
        if d.get(b) != None:
            d[b] +=1
        else:
            d[b]=1
            l.append(b)
    
    for idx in l:
        answer *=(d[idx]+1)  # 하나가 더해진 이유는 입지 않은 경우도 포함.
    print(answer-1) # 아무것도 안 걸친 경우를 빼줘야 한다.
    d.clear()
    l.clear()
    

import sys
sys.setrecursionlimit(111111)
def dfs(curr):
    global answer
    visit[curr]=True
    number.append(curr)
    curr_num = adj[curr]
    if visit[curr_num]== False:
        dfs(curr_num)
    else:
        if curr_num in number: # 현재 수가 number 안에 있으면 그 수는 그 자리부터 Cycle이다.
            answer += number[number.index(curr_num):] # index 함수는 중복 수에서 가장 최근에 마지막에 나온 수를 반환
        return

T = int(sys.stdin.readline())
for _ in range(T):
    V = int(sys.stdin.readline())
    visit = [False] * (V + 1)
    answer = list()
    adj =[0] + list(map(int, sys.stdin.readline().split()))
    for i in range(1, V+1):
        if visit[i] == False:
            number = []
            dfs(i)
    print(V - len(answer))

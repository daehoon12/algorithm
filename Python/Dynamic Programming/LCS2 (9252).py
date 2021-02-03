import sys
from collections import deque

s1 = '0' + sys.stdin.readline().strip()
s2 = '0'+ sys.stdin.readline().strip() # 맨 앞에 0을 채워줌. 관습
dp= [[0]*len(s1) for _ in range(len(s2))]
for i in range(len(s2)):
    for j in range(len(s1)):
        if i==0 or j==0: # 인덱스가 0이면 값이 0이게 그냥 놔둠.
            continue

        if s1[j] == s2[i]: # 값이 같으면 대각선의 dp값에 1을 더하고
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]) # 아니면 자신의 위와 왼쪽을 비교해 큰 값을 선택

i = len(s2)-1
j = len(s1)-1

st = deque()
while dp[i][j]: # 문자열의 끝부터 시작. stack에 넣을 것
    if dp[i][j] ==dp[i][j-1]:
        j-=1
    elif dp[i][j] == dp[i-1][j]:
        i-=1
    elif dp[i][j]-1 ==dp[i-1][j-1]: # 현재 값 -1 == 대각선이면 같은 문자. 스택에 넣고 인덱스를 줄여준다.
        st.append(j)
        i-=1
        j-=1
print(dp[len(s2)-1][len(s1)-1])

while st:
    print(s1[st.pop()], end='')

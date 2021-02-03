import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().strip().split()))
dp=[0]*(n+1)
for i in range(n):
    dp[i]=1
    for j in range(i):
        if arr[i] > arr[j] and dp[i] < dp[j]+1: # j와 i를 비교하는데 arr[i]가 더 크고, j값의 dp가 더 크면 dp[i]에 dp[j] +1 저장.
            dp[i] = dp[j]+1 
print(max(dp))

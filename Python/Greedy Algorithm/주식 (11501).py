import sys
T = int(sys.stdin.readline())
# 거꾸로 시작해 고점이면 계속 놔두고 저점이면 팔아야 함.

for _ in range(T):
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    start = arr[n-1]
    answer=0
    for i in arr[n-2::-1]:
        if start <i:
            start =i
        else:
            answer += start -i
    print(answer)

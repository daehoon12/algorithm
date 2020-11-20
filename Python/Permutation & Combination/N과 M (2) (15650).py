from itertools import combinations
import sys
N, M =map(int, sys.stdin.readline().split())
p = (combinations(range(1,N+1), M))
for i in p:
    print(*i)

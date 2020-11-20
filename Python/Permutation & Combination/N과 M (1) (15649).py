from itertools import permutations
import sys
N, M =map(int, sys.stdin.readline().split())
p = (list(permutations(range(1,N+1), M)))
for i in p:
    print(*i)

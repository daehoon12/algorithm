# C++을 이용할 때는 parsing할때 조건문을 많이 써야했는데 파이썬으로 짜면 코드가 간결하다..

import sys

str = sys.stdin.readline().strip().split('-') # 먼저 -로 나누고
answer=0
for i in str[0].split('+'): # +로 나눈뒤
    answer+=int(i) # 맨 첫번째 원소는 항상 양수니까 더함

for i in str[1:]:
    for j in i.split('+'): # 그 다음 +가 들어있는 식은 앞에 항상 음수가 있다고 생각하고
        answer -=int(j) # 빼준다!
print(answer)

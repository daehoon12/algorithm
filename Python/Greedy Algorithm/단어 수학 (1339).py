import sys

n = int(sys.stdin.readline())
words =[]
alpha = [0]*26
for i in range(n):
    ip = list(sys.stdin.readline().strip())
    words.append(ip)

for word in words:
    exp = len(word)-1
    for i in word:
        alpha[ord(i) - ord('A')] += pow(10, exp) # 이게 KeyPoint 각 알파벳에서 나오는 값들을 누적해서 더해줘야 한다.
        exp-=1
alpha = sorted(alpha, reverse=True) # 내림차순 sort
answer=0
prev_alpha=-1
num=9
for i in alpha:
    answer += i * num
    num-=1
print(answer)

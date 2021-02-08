def solution(s):
    answer = 1
    if len(s) ==1:
        return 1
    for i in range(len(s)):
        for j in range(i, len(s)+1): # 완전 탐색. 맨 처음부터 검색해 슬라이싱하고 거꾸로 해도 같은지 판별한다.
            st = s[i:j]
            if st==st[::-1]:
                answer= max(answer, len(st))
    return answer

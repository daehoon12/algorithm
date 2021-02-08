def solution(s):
    length = []
    result = ""
    
    if len(s) == 1:
        return 1
    
    for cut in range(1, len(s) // 2 + 1): # 문자열을 판별할 범위 1,2,3,4
        count = 1
        tempStr = s[:cut] 
        for i in range(cut, len(s), cut):
            if s[i:i+cut] == tempStr: # 범위 내 길이가 같으면 count 증가 
                count += 1
            else:
                if count == 1: # 아닐시 1이면 1을 없애기 위해 count =""
                    count = ""
                result += str(count) + tempStr 
                tempStr = s[i:i+cut]
                count = 1

        if count == 1:
            count = ""
        result += str(count) + tempStr
        length.append(len(result))
        result = ""
    
    return min(length)

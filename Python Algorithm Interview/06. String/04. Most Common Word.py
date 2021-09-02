from collections import defaultdict
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        words = [word for word in re.sub('[^\w]', ' ', paragraph).lower().split()]
        dic = defaultdict(int)
        for word in words:
            if word not in banned:
                dic[word]+=1
        return Counter(dic).most_common()[0][0]
        

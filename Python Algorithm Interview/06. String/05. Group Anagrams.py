from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ana=defaultdict(list)
        for str in strs:
            ana["".join(sorted(str))].append(str)
        return ana.values()

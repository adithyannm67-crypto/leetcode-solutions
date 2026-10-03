class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lens = []
        subLen = 0
        max = 0
        i = 0
        sub = ""

        for c in s:
            if c in sub:
                sub=sub[sub.find(c)+1:]
                sub+= c
                if subLen > max:
                    max = subLen
            else:
                sub += c
                subLen = len(sub)
                # max=subLen

        if max > subLen:
            return max
        else:
            return subLen

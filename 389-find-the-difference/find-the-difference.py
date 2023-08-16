class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_dict = {}
        for char in s:
            if char in s_dict:
                s_dict[char] += 1
            else :
                s_dict[char] = 1
        
        for char in t:
            if char in s_dict:
                s_dict[char] -= 1
                if s_dict[char] == 0:
                    s_dict.pop(char)
            else:
                return char
        return ""
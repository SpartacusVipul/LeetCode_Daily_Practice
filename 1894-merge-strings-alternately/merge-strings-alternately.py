class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        res_list = []
        max_size = max(len(word1), len(word2))
        for i in range(max_size):
            if i < len(word1):
                res_list.append(word1[i])
            if i < len(word2):
                res_list.append(word2[i])
        return "".join(res_list)
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        char_set = set('abcdefghijklmnopqrstuvwxyz')
        seen_set = set()

        for char in sentence:
            if char in char_set:
                seen_set.add(char)
            if len(seen_set) == 26:
                return True
        return False
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        cur_num = 2
        prev_num = 1
        for i in range (1, x // 2):
            if cur_num*cur_num > x:
                break
            cur_num += 1
            prev_num += 1

        return prev_num
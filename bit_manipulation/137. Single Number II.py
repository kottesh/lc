class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ones, twos = 0, 0

        for num in nums:
            ones = (ones ^ num) & ~twos
            twos = (twos ^ num) & ~ones

        return ones
    #def singleNumber(self, nums: List[int]) -> int:
    #    store = {}

    #    for num in nums:
    #        if num not in store:
    #           store[num] = 1 
    #        else:
    #            store[num] += 1
    #    
    #    ans = 0
    #    for key, val in store.items():
    #        if val == 1:
    #            ans = key
    #            break
    #    
    #    return ans

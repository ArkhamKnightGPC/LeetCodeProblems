class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        lgt = len(nums)
        dic = {}

        for i in range(lgt):
            need = target - nums[i]
            if need in dic:
                return[dic[need], i]
            dic[nums[i]] = i
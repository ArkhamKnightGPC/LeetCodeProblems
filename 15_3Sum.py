class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        n : int = len(nums)
        max_val : int = 100000
        for i in range(0, n):
            nums[i] += max_val # now 0 <= nums[i] <= 10**5 and we want nums[i]+nums[j]+nums[k]==300000

        chk : list[bool] = [False]*(3*max_val+1)
        ret : list[list[int]] = []
        chk_unique : dict = {}
        for i in range(0, n):
            for j in range(i+1, n):
                need : int = 3*max_val - (nums[i]+nums[j])
                if chk[need]:
                    sol : list[int] = [nums[i]-max_val, nums[j]-max_val, need-max_val] #undo transformation to get solution
                    sol.sort() #sort to make sure it is unique
                    if tuple(sol) not in chk_unique.keys():
                        ret.append(sol)
                        chk_unique[tuple(sol)] = True
            chk[nums[i]] = True #index i gets left behind => mark it!!
        return ret

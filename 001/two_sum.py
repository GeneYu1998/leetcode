class Solution:
    def twoSum(self, nums: list, target: int) -> list:
        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []

########### test #############
sol_1 = Solution()
print(sol_1.twoSum(nums = [2, 7, 11, 15, 20, 40, 50, 30, 10, 80, 120, 130], target = 100))
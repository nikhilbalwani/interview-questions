class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        occured = {}
        
        for index, num in enumerate(nums):
            
            if target - num in occured:
                prev_index = occured[target - num]
                return [prev_index, index]
            
            occured[num] = index

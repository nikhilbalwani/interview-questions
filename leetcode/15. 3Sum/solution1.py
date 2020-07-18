class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        if len(nums) < 3:
            return []
        
        nums.sort()
        
        curr_master_ele = None
        prev_j_ele = None
        prev_k_ele = None
        solution_set = []
        
        for i in range(len(nums) - 2):
            if curr_master_ele != nums[i]:
                curr_master_ele = nums[i]
            
            else:
                continue
            
            j = i + 1
            k = len(nums) - 1
            
            while j < k:
                curr_sum = curr_master_ele + nums[j] + nums[k]
                
                if curr_sum == 0:
                    
                    if prev_j_ele == nums[j] and prev_k_ele == nums[k]:
                        j += 1
                        k -= 1
                        
                        continue
                    
                    solution_set.append([curr_master_ele,
                                        nums[j],
                                        nums[k]])
                    
                    prev_j_ele = nums[j]
                    prev_k_ele = nums[k]
                    
                    j += 1
                    k -= 1
                
                elif curr_sum > 0:
                    k -= 1
                
                else:
                    j += 1
            
        return solution_set

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        result_set = []
        
        if len(nums) < 4:
            return []
        
        nums.sort()
        
        prev_element_i = None
        
        for i in range(len(nums) - 3):
            
            element_i = nums[i]
            
            if element_i == prev_element_i:
                continue
            
            prev_element_i = element_i
            
            prev_element_j = None
            
            for j in range(i + 1, len(nums) - 2):
                
                element_j = nums[j]
                
                if prev_element_j == element_j:
                    continue
                
                prev_element_j = element_j
                
                k = j + 1
                l = len(nums) - 1
                
                prev_element_k = None
                prev_element_l = None
                
                while k < l:
                    element_k = nums[k]
                    element_l = nums[l]
                    
                    curr_sum = element_i + element_j +\
                               element_k + element_l
                    
                    if curr_sum == target:
                        
                        if prev_element_k == element_k and prev_element_l == element_l:
                            k += 1
                            l -= 1
                            continue
                        
                        result_set.append([element_i, element_j,
                                           element_k, element_l])
                        
                        prev_element_k = element_k
                        prev_element_l = element_l
                        
                        k += 1
                        l -= 1
                        
                    elif curr_sum > target:
                        l -= 1
                    
                    else:
                        k += 1
        
        return result_set

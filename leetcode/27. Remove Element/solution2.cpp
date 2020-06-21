class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int curr_size = nums.size();
        
        for (int i = 0; i < curr_size; ++i) {
            int j = curr_size - 1;

            while (j > -1 && nums[j] == val) {
                curr_size -= 1;
                j -= 1;
            }
            
            if (i >= curr_size) {
                return curr_size;
            }
            
            if (nums[i] == val) {
                nums[i] = nums[curr_size - 1];
                curr_size -= 1;
            }
        }
        
        return curr_size;
    }
};

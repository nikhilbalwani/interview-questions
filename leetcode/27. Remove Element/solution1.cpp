class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int i = 0;
        
        while (i < nums.size() && nums[i] != val) {
            i += 1;
        }
        
        // nums[i] = val now
        
        int j = i + 1;
        int cnt = i;
        
        for (; j < nums.size(); ++j) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                cnt += 1;
                i += 1;
            }
        }
        
        return cnt;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ret = 1;
        int curr_num = nums[0];
        
        int j = 1;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != curr_num) {
                nums[j] = nums[i];
                j++;
                curr_num = nums[i];
            }
        }
        
        return j;
    }
};
